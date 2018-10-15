#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int v[100002] = {0};
int dp[100002] = {0};
int dp2[100002] = {0};

int main(){
  int n = 0, temp = -2000000000, temp2 = -2000000000;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }

  //1. 수를 제거하지 않았을 때
  for(int i = n-1; i >= 0; i--){
    if(dp[i+1] > 0)
      dp[i] = v[i] + dp[i+1];
    else
      dp[i] = v[i];

    temp = max(temp, dp[i]);
  }

  for(int i = 0; i < n; i++){
    if(i > 0 & dp2[i-1] > 0)
      dp2[i] = v[i] + dp2[i-1];
    else
      dp2[i] = v[i];
  }

  //2. 수를 제거했을 때(음수를 제거한다)
  for(int i = 1; i < n-1; i++){
    if(v[i] >= 0)
      continue;
    temp2 = max(temp2, dp[i+1] + dp2[i-1]);
  }

  printf("%d\n", max(temp, temp2));
  return 0;
}
