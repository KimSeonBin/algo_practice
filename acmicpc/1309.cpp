#include <stdio.h>

int main(){
  int n = 0, moduler = 9901;
  scanf("%d", &n);

  int dp[100001] = {0};
  dp[0] = 1;
  dp[1] = 3;
  for(int i = 1; i < n; i++){
    dp[i+1] = (dp[i] * 2 + dp[i-1]) % moduler;
  }

  printf("%d\n", dp[n]);
  return 0;
}
