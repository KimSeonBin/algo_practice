#include <stdio.h>

int main(){
  int n = 0;
  int nump[100001] = {0};
  int dp[100001] = {0};
  int answer = -2000000000;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &nump[i]);
  }
  dp[n-1] = nump[n-1];
  for(int i = (n-1)-1; i >= 0; i--){
    dp[i] = (nump[i] > nump[i] + dp[i+1]) ? nump[i] : nump[i] + dp[i+1];
  }

  for(int i = 0; i < n; i++){
    answer = (answer > dp[i]) ? answer : dp[i];
  }
  printf("%d\n", answer);
  return 0;
}
