#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;
int dp[1001] = {0};

int max(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main(){
  int n = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    int temp = 0;
    scanf("%d", &temp);
    v.push_back(temp);
  }

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(v[j] > v[i]){
        dp[j] = max(dp[j], dp[i]+1);
      }
    }
  }

  int answer = 0;
  for(int i = 0; i < n; i++)
    answer = max(answer, dp[i]);

  printf("%d\n", answer+1);
  return 0;
}
