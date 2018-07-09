#include <stdio.h>
#include <vector>
using namespace std;

int main(){
  int n = 0;
  scanf("%d", &n);

  vector<int> answer;
  answer.push_back(1);
  answer.push_back(2);
  for(int i = 1; i < n; i++){
    answer.push_back((answer[i]+answer[i-1])%10007);
  }
  printf("%d\n", answer[n-1] % 10007);
  return 0;
}
