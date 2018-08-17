#include <stdio.h>
#define modul 1000000009
int dp[1001][1001] = {0};
int main(){
  dp[1][1] = 1;
  dp[2][1] = 1;
  dp[3][1] = 1;
  for(int i = 2; i <= 1000; i++){
    for(int j = 2; j <= 1000; j++){
      for(int k = 1; k <= 3; k++){
        if(j-k > 0)
          dp[j][i] = (dp[j][i] + dp[j-k][i-1]) % modul;
      }
    }
  }


  int t = 0;
  scanf("%d", &t);

  for(int iter = 0; iter < t; iter++){
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    printf("%d\n", dp[a][b]);
  }

  return 0;
}
