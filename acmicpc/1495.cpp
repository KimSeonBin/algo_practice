#include <stdio.h>

int vol[101] = {0};
bool dp[101][1001] = {0};


int main(){
  int n = 0, s = 0, m = 0;
  scanf("%d %d %d", &n, &s, &m);
  for(int i = 1; i <= n; i++){
    scanf("%d", &vol[i]);
  }

  dp[0][s] = true;
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= m; j++){
      if(dp[i-1][j]){
        if(j + vol[i] <= m){
          dp[i][j+vol[i]] = true;
        }
        if(j - vol[i] >= 0){
          dp[i][j-vol[i]] = true;
        }
      }
    }
  }
  int max = -1;
  for(int i = 0; i <= m; i++){
    if(dp[n][i])
      max = i;
  }
  printf("%d\n", max);
  return 0;
}
