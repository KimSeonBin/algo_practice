#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

typedef struct node{
  int dest;
  int cost;
};

typedef struct dji{
  int cost;
  vector<int> route;
};

int main(){
  int n = 0, m = 0;
  scanf("%d", &n);
  scanf("%d", &m);
  bool check[1001] = {false};
  vector<vector<node>> map;
  dji answer[1001];
  queue<int> q;

  for(int i = 0; i < n; i++){
    vector<node> temp;
    map.push_back(temp);
    answer[i].cost = 1000000000;
  }
  int temp1 = 0, temp2 = 0, temp3 = 0;
  for(int i = 0; i < m; i++){
    scanf("%d %d %d", &temp1, &temp2, &temp3);
    node ttt;
    ttt.dest = temp2-1;
    ttt.cost = temp3;
    map[temp1-1].push_back(ttt);
  }

  int start = 0, dest = 0;
  scanf("%d %d", &start, &dest);
  start--; dest--;

  check[start] = true;
  answer[start].cost = 0;
  answer[start].route.push_back(start);
  q.push(start);
  while(!q.empty()){
    int t = q.front();
    q.pop();
    if(t == dest){
      break;
    }
    for(int i = 0; i < map[t].size(); i++){
      if(check[map[t][i].dest] == true){
        continue;
      }
      if(answer[map[t][i].dest].cost > answer[t].cost + map[t][i].cost){
        answer[map[t][i].dest].cost = answer[t].cost + map[t][i].cost;
        answer[map[t][i].dest].route.clear();
        for(int j = 0; j < answer[t].route.size(); j++){
          answer[map[t][i].dest].route.push_back(answer[t].route[j]);
        }
        answer[map[t][i].dest].route.push_back(map[t][i].dest);
      }
    }

    int tt = 1000000000;
    int pos = 0;
    for(int i = 0; i < n; i++){
      if(check[i] == true){
        continue;
      }
      if(tt > answer[i].cost){
        tt = answer[i].cost;
        pos = i;
      }
    }
    check[pos] = true;

    q.push(pos);
  }

  printf("%d\n", answer[dest].cost);
  printf("%d\n", answer[dest].route.size());
  for(int i = 0; i < answer[dest].route.size(); i++){
    printf("%d ", answer[dest].route[i]+1);
  }
  printf("\n");

  return 0;
}
