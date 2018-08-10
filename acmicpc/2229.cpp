#include <stdio.h>
#include <vector>
#include <algorithm>
#define minx(a, b) ((a) < (b) ? (a) : (b))
#define maxx(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

vector<int> stu;
int sub[1001][1001];
int dp[1001][1001];

int main(){
  int n = 0, temp = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    stu.push_back(temp);
  }

  for(int i = 0; i < n; i++){
    int minn = stu[i], maxn = stu[i];
    for(int j = i+1; j < n; j++){
      minn = minx(minn, stu[j]);
      maxn = maxx(maxn, stu[j]);
      sub[i+1][j+1] = maxn - minn;
    }
  }

  /*
  dp[i][j] -> i~j 까지의 부분 집합 최대값
  */
  for(int i = n-1; i > 0; i--){
    for(int j = i+1; j <= n; j++){
      for(int k = i; k < j; k++){
        dp[i][j] = maxx(dp[i][j], dp[i][k] + dp[k+1][j]);
      }
      dp[i][j] = maxx(dp[i][j], sub[i][j]);
    }
  }

  printf("%d\n", dp[1][n]);
  return 0;
}
