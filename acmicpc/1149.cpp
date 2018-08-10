#include <stdio.h>
#define minn(a, b) ((a) < (b) ? (a) : (b))
#define INF 2000000000

int rgbbox[1001][4];
int dp[1001][4];
int main(){
  int n = 0;
  scanf("%d", &n);

  int r = 0, g = 0, b = 0;
  for(int i = 1; i <= n; i++){
    scanf("%d %d %d", &r, &g, &b);
    rgbbox[i][1] = r;
    rgbbox[i][2] = g;
    rgbbox[i][3] = b;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 3; j++){
      dp[i][j] = INF;
      for(int k = 1; k <= 3; k++){
        if(j == k)
          continue;
        dp[i][j] = minn(dp[i][j], dp[i-1][k] + rgbbox[i][j]);
      }
    }
  }

  int answer = INF;
  for(int i = 1; i <= 3; i++){
    answer = minn(answer, dp[n][i]);
  }
  printf("%d\n", answer);
  return 0;
}
