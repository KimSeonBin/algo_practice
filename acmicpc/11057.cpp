#include <stdio.h>

int main(){
  int n = 0;
  scanf("%d", &n);

  int dp[1001][10] = {0};
  int total = 0, moduler = 10007;
  for(int i = 0; i < 10; i++){
    dp[1][i] = 1;
    total++;
  }

  for(int i = 2; i <= n; i++){
    dp[i][0] = total;
    for(int j = 1; j < 10; j++){
      dp[i][j] = (dp[i][j-1] - dp[i-1][j-1]) % moduler;
      if(dp[i][j] < 0){
        dp[i][j] += moduler;
      }
    }
    total = 0;
    for(int j = 0; j < 10; j++){
      //total = (total + dp[i][j]) % moduler;
      total = (total + dp[i][j]) % moduler;
    }
  }

  printf("%d\n", total % moduler);
  return 0;
}
