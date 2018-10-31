#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int dp[300001] = {0};

int main(){
  int n = 0, answer = 1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int temp;
    scanf("%d", &temp);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  for(int i = n-1; i >= 0; i--){
    // 각 이전단계까지 가장 큰 race 결과 값 저장 후 비교에 쓴다.
    dp[i] = max(dp[i+1], v[i] + (n-i));
  }

  for(int i = n-2; i >= 0; i--, answer++){
    if(v[i] + n < dp[i])
      break;
  }

  printf("%d\n", answer);
}
