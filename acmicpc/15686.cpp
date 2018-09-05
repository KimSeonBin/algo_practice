#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct building{
  int x, y;
};

vector<building> house;
vector<building> chicken;
int maps[51][51];
int distances[102][15];

int minvv(int a, int b){
  if(a < b)
    return a;
  return b;
}

int backtracking(vector<int> what_chicken, int m, int startindex){
  if(what_chicken.size() == m){
    int result = 0;
    for(int i = 1; i <= 100; i++){
      if(distances[i][1] == 0)
        break;
      int temp = 2000000000;
      for(int j = 0; j < m; j++){
        if(distances[i][what_chicken[j]+1] == 0)
          break;
        temp = minvv(temp, distances[i][what_chicken[j]+1]);
      }
      result += temp;
    }
    return result;
  }

  int returnv = 2000000000;
  for(int i = startindex; i < chicken.size(); i++){
    what_chicken.push_back(i);
    returnv = minvv(returnv, backtracking(what_chicken, m, i+1));
    what_chicken.pop_back();
  }

  return returnv;
}

int main(){
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      scanf("%d", &maps[i][j]);
      building temp;
      temp.x = i; temp.y = j;
      if(maps[i][j] == 1){
        house.push_back(temp);
      }
      else if(maps[i][j] == 2){
        chicken.push_back(temp);
      }
    }
  }

  for(int i = 1; i <= house.size(); i++){
    for(int j = 1; j <= chicken.size(); j++){
      distances[i][j] = abs(house[i-1].x - chicken[j-1].x) + abs(house[i-1].y - chicken[j-1].y);
    }
  }

  vector<int> what;
  printf("%d\n", backtracking(what, m, 0));
  return 0;
}
