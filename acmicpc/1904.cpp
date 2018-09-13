#include <stdio.h>
#define moduler 15746

int dp[1000001];

/*
1: 1
2: 2
3: 3
4: 5
5: 8
6: 13
7: 21
*/
int main(){
  int n = 0;
  scanf("%d", &n);

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  for(int i = 4; i <= n; i++){
    dp[i] = (dp[i-1] + dp[i-2]) % moduler;
  }
  printf("%d\n", dp[n]);
  return 0;
}
