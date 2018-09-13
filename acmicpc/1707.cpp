#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr[20001];
queue<int> q;
int check[20001];

int main(){
  int t = 0; scanf("%d", &t);
  for(int iter = 0; iter < t; iter++){
    int v = 0, e = 0;
    scanf("%d %d", &v, &e);
    for(int i = 0; i < e; i++){
      int x = 0, y = 0;
      scanf("%d %d", &x, &y);
      arr[x].push_back(y);
      arr[y].push_back(x);
    }

    bool isbinary = true;
    for(int i = 1; i <= v; i++){
      if(arr[i].size() == 0 || check[i] > 0)
        continue;

      check[i] = 1;

      q.push(i);
      while(!q.empty()){
        int qf = q.front(); q.pop();
        for(int j = 0; j < arr[qf].size(); j++){
          if(check[arr[qf][j]] == 0){
            if(check[qf] == 1)
              check[arr[qf][j]] = 2;
            else
              check[arr[qf][j]] = 1;
            q.push(arr[qf][j]);
          }
          else{
            if(check[qf] == check[arr[qf][j]]){
              isbinary = false;
              break;
            }
          }
        }
      }
      if(!isbinary)
        break;
    }

    if(isbinary)
      printf("YES\n");
    else
      printf("NO\n");

    for(int i = 1; i <= v; i++){
      arr[i].clear();
      check[i] = 0;
    }
    while(!q.empty()){
      q.pop();
    }

  }
  return 0;
}
