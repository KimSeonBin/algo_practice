#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;


int main(){
  int t = 0;
  scanf("%d", &t);
  for(int iter = 0; iter < t; iter++){
    int n = 0, k = 0, temptime = 0;
    int start = 0, dest = 0;
    int finaldest = 0;
    vector<vector<int>> building;
    vector<int> timer;
    queue<int> q;
    int check[1001] = {0};
    int timee[1001] = {0};

    scanf("%d %d", &n, &k);

    //건물 짓는 시간
    for(int i = 0; i < n; i++){
      vector<int> temp;
      building.push_back(temp);
      scanf("%d", &temptime);
      timer.push_back(temptime);
    }

    //건물 규칙
    for(int i = 0; i < k; i++){
      scanf("%d %d", &start, &dest);
      building[start-1].push_back(dest-1);
      check[dest-1]++;
    }
    scanf("%d", &finaldest);finaldest--;

    //위상정렬 초기화
    for(int i = 0; i < n; i++){
      if(check[i] == 0){
        q.push(i);
        check[i] = -1;
        timee[i] = timer[i];
      }
    }

    while(!q.empty()){
        int itemp = q.front();
        q.pop();
        if(itemp == finaldest){
          break;
        }
        for(int i = 0; i < building[itemp].size(); i++){
          check[building[itemp][i]]--;
          if(timee[building[itemp][i]] < timer[building[itemp][i]] + timee[itemp]){
            timee[building[itemp][i]] = timer[building[itemp][i]] + timee[itemp];
          }
        }

        for(int i = 0; i < n; i++){
          if(check[i] == 0){
            q.push(i);
            check[i] = -1;
          }
        }
    }

    printf("%d\n", timee[finaldest]);
  }
  return 0;
}
