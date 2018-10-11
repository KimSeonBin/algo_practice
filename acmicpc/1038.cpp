#include <cstdio>
#include <vector>

using namespace std;

int arr[11][11] = {0};

// 최대 가능한 수는 9876543210
// 그 이상은 불가능
// 따라서 10자리수까지 총 개수를 구해 초과하면 -1

int main(){
  int n = 0, total = 0;
  long long answer = 0;
  scanf("%d", &n);

  arr[1][0] = 1;
  for(int i = 1; i < 11; i++){
    arr[i][10] = total; // 현재 단계까지의 총 개수
    for(int j = 1; j < 10; j++){
      arr[i][j] = arr[i-1][j-1] + arr[i][j-1];
      total += arr[i][j];
    }
  }

  if(n > total){
    printf("-1\n");
    return 0;
  }

  arr[1][0] = 0;
  int previous = 10;
  for(int i = 10; i >= 1; i--){
    if(n <= arr[i][10])
      continue;

    for(int j = previous; j < 10; j++){
      n -= arr[i][j];
    }

    int temp = arr[i][10];
    for(int j = 0; j < 10; j++){
      if(temp + arr[i][j] >= n){
        n -= (temp + arr[i][j] - arr[i][10]);
        answer = answer * 10 + j;
        previous = j;
        break;
      }
      temp += arr[i][j];
    }
  }

  printf("%lld\n", answer);
  return 0;
}
