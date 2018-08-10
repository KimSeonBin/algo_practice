#include <stdio.h>
#define modul 1000000000

int dp[201][201];

int main(){
  int n = 0, k = 0;
  scanf("%d %d", &n, &k);

  for(int i = 1; i <= 200; i++){
    dp[1][i] = 1;
  }
  for(int i = 2; i <= k; i++){
    dp[i][1] = dp[i-1][1]+1;
    for(int j = 2; j <= n; j++){
      dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % modul;
    }
  }

  printf("%d\n", dp[k][n]);
  return 0;
}
