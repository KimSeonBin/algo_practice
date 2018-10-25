#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

// 1 2 3
// 1 2 3 4 5 6

// 1 2 4
// 1 2 3 4 5 6 7

// 1 2 5
// 1 2 3 5 6 7 8

//이전 단계의 sum과 비교해 2이상 차이나면 간격이 생김

int main(){
  int n = 0, answer = 0, sum = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    int t;
    scanf("%d", &t);
    v.push_back(t);
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    if(v[i] - sum > 1){
      answer = sum + 1;
      break;
    }

    sum += v[i];
  }

  if(answer == 0)
    answer = sum + 1;

  printf("%d\n", answer);
  return 0;
}
