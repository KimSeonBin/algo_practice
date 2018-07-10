/*
http://debuglog.tistory.com/78
dp[i][j] = dp[i-1][j] + dp[i][j-coin];
*/

#include <stdio.h>

int main(){
  int n = 0, k = 0;
  scanf("%d %d", &n, &k);
  int dp[100001] = {0}, coin = 0;
  for(int iter = 0; iter < n; iter++){
    scanf(" %d", &coin);
    dp[coin]++;
    for(int i = coin+1; i < k+1; i++){
      dp[i] = dp[i] + dp[i-coin];
    }
    // for(int i = 0; i <= k; i++)
    //   printf("%d ", dp[i]);
    // printf("\n");
  }
  printf("%d\n", dp[k]);
  return 0;
}
