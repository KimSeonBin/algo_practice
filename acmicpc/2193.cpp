#include <stdio.h>

int main(){
  int n = 0;
  scanf("%d", &n);

  long long dp[91] = {0};
  dp[1] = 1;
  dp[2] = 1;
  for(int i = 3; i <= 90; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  printf("%lld\n", dp[n]);
  return 0;
}
