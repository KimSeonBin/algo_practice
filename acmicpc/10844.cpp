#include <stdio.h>

int main(){
  int n = 0, answer = 0;
  int moduler = 1000000000;
  scanf("%d", &n);
  int dp[101][12] = {0};
  for(int i = 0; i < 10; i++){
    dp[1][i] = 1;
  }
  for(int i = 2; i <= n; i++){
    dp[i][0] = dp[i-1][1];
    for(int j = 1; j < 9; j++){
      dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % moduler;
    }
    dp[i][9] = dp[i-1][8];
  }
  for(int i = 1; i < 10; i++){
    answer = (answer + dp[n][i]) % moduler;
  }
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j < 10; j++){
  //     printf("%d ", dp[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%d\n", answer);
  return 0;
}
