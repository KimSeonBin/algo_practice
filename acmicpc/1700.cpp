#include <cstdio>

using namespace std;

int tap[101] = {0};
int arr[101] = {0};

int main(){
  int n = 0, k = 0, answer = 0;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < k; i++){
    scanf("%d", &arr[i]);
  }

  for(int i = 0; i < k; i++){
    bool ispull = true;
    for(int j = 0; j < n; j++){
      if(tap[j] == 0 || tap[j] == arr[i]){
        tap[j] = arr[i];
        ispull = false;
        break;
      }
    }

    if(!ispull)
      continue;

    int temp = -1, check[101] = {0}, pullindex = 0;
    // tap에 꽂혀있는 콘센트 중 가장 늦게 나오는 콘센트를 뽑는다.
    for(int j = 0; j < n; j++){
      check[j] = 1000;
      for(int q = i+1; q < k; q++){
        if(tap[j] == arr[q]){
          check[j] = q;
          break;
        }
      }
    }

    for(int j = 0; j < n; j++){
      if(temp < check[j]){
        pullindex = j;
        temp = check[j];
      }
    }

    tap[pullindex] = arr[i];
    answer++;
  }
  printf("%d\n", answer);
  return 0;
}
