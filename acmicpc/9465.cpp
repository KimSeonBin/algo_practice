#include <stdio.h>

int max(int a, int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(){
  int t = 0;
  int n = 0;
  int answer = 0;
  scanf("%d", &t);
  for(int iter = 0; iter < t; iter++){
    scanf("%d", &n);
    int sticker[2][100001] = {0};
    int dp[2][100001] = {0};
    for(int i = 0; i < 2; i++){
      for(int j = 0; j < n; j++){
        scanf("%d", &sticker[i][j]);
      }
    }

    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];

    for(int i = 1; i < n; i++){
      dp[0][i] = max(dp[0][i-1], dp[1][i-1]+sticker[0][i]);
      dp[1][i] = max(dp[1][i-1], dp[0][i-1]+sticker[1][i]);
    }

    answer = max(dp[0][n-1], dp[1][n-1]);
    printf("%d\n", answer);
  }
  return 0;
}
