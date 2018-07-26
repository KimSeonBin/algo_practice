//http://js1jj2sk3.tistory.com/3
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
  int t = 0;
  scanf("%d", &t);
  for(int iter = 0; iter < t; iter++){
    int k = 0;
    int temp1 = 0, temp2 = 0;
    int files[501] = {0};
    int dp[501][501] = {0};
    int cost[501] = {0};
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
      scanf("%d", &files[i]);
    }

    cost[1] = files[0];
    for(int i = 2; i <= k; i++){
      cost[i] = cost[i-1] + files[i-1];
    }

    for(int i = 1; i < k; i++){
      for(int j = 1; i+j <= k; j++){
        int ty = i+j;
        dp[j][ty] = 2000000000;
        for(int p = j; p < ty; p++){
          dp[j][ty] = min(dp[j][ty], dp[j][p] + dp[p+1][ty] + (cost[ty] - cost[j-1]));
        }
      }
    }

    printf("%d\n", dp[1][k]);
  }

  return 0;
}
