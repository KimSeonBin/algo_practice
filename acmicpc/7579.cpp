#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct info{
  int me;
  int cost;
  bool operator< (info a){
    return this->cost < a.cost;
  }
};

//cost를 dp로 인자로?
int maxx(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main(){
  int n = 0, m = 0, temp = 0;
  int answer = 2000000000;
  scanf("%d %d", &n, &m);
  vector<info> app;

  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    info t;
    t.me = temp;
    app.push_back(t);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    app[i].cost = temp;
  }
  sort(app.begin(), app.end());

  int tempcost = 0, tempmemory = 0;
  int dp[10201] = {0};
  int tempp[10201] = {0};
  int a = m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < 10201; j++){
      if(dp[j] == 0 || j+app[i].cost >= 10201){
        continue;
      }
      tempp[j+app[i].cost] = maxx(tempp[j+app[i].cost], dp[j]+app[i].me);
    }
    tempp[app[i].cost] = maxx(tempp[app[i].cost], app[i].me);
    for(int j = 0; j < 10201; j++){
      dp[j] = tempp[j];
    }
  }

  for(int i = 0; i < 10201; i++){
    if(dp[i] >= a){
      answer = i;
      break;
    }
  }
  printf("%d\n", answer);
  return 0;
}
