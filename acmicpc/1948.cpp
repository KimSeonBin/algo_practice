#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


typedef struct road{
  int x, time;
};
vector<road> v[10001];
vector<road> backv[10001];
int count[10001] = {0};
int maxtime[10001] = {0};
bool check[10001] = {false};

queue<int> q;

int maxx(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main(){
  int answer_time = 0, answer_count = 0;
  int n = 0, m = 0;
  scanf("%d\n%d", &n, &m);
  for(int i = 0; i < m; i++){
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    road temp;
    temp.x = b; temp.time = c;
    v[a].push_back(temp);

    road temp2;
    temp2.x = a; temp2.time = c;
    backv[b].push_back(temp2);

    count[b]++;
  }

  int s = 0, e = 0;
  scanf("%d %d", &s, &e);

  for(int i = 1; i <= n; i++){
    if(count[i] > 0)
      continue;

    q.push(i);
  }

  while(!q.empty()){
    int index = q.front(); q.pop();
    int currenttime = maxtime[index];

    for(int i = 0; i < v[index].size(); i++){
      count[v[index][i].x]--;
      if(count[v[index][i].x] == 0){
        q.push(v[index][i].x);
        count[v[index][i].x] = -1;
      }

      maxtime[v[index][i].x] = maxx(maxtime[v[index][i].x], v[index][i].time + maxtime[index]);
    }
  }

  answer_time = maxtime[e];

  q.push(e);
  // check[e] = true;
  while(!q.empty()){
    int index = q.front(); q.pop();
    for(int i = 0; i < backv[index].size(); i++){
      if(maxtime[index]-backv[index][i].time == maxtime[backv[index][i].x]){
        if(check[index])
          continue;
        q.push(backv[index][i].x);
        answer_count++;
      }
    }
    check[index] = true;
  }

  printf("%d\n%d\n", answer_time, answer_count);
  return 0;
}
