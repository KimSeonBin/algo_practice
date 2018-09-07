#include <stdio.h>
#include <vector>
#include <queue>
#define maxv 1000000002
using namespace std;

typedef struct bridge{
  int y, weight;
};

vector<bridge> arr[100001];
int maxdistance[100001];
queue<int> q;

int maxx(int a, int b){
  if(a > b)
    return a;
  return b;
}

int minn(int a, int b){
  if(a < b)
    return a;
  return b;
}

int main(){
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    int a = 0, b = 0, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    bridge temp;
    temp.y = b; temp.weight = c;
    arr[a].push_back(temp);
    bridge temp2;
    temp2.y = a; temp2.weight = c;
    arr[b].push_back(temp2);
  }

  int start = 0, dest = 0;
  scanf("%d %d", &start, &dest);
  maxdistance[start] = maxv;
  q.push(start);

  while(!q.empty()){
    int index = q.front(); q.pop();
    for(int i = 0; i < arr[index].size(); i++){
      int newy = arr[index][i].y;
      if(newy == start)
        continue;
      if(maxdistance[newy] == 0){
        maxdistance[newy] = minn(maxdistance[index], arr[index][i].weight);
        q.push(newy);
      }
      else{
        int limit = minn(maxdistance[index], arr[index][i].weight);
        if(limit > maxdistance[newy]){
          q.push(newy);
          maxdistance[newy] = limit;
        }
      }
    }
  }

  printf("%d\n", maxdistance[dest]);
  return 0;
}
