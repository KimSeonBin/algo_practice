#include <cstdio>
#define MODULER 1000000007L

long long arr[100001] = {0};
long long sumv[100001] = {0};
long long mulv[100001] = {0};

/*
5
1 2 3 4 5
225

5
1 3 3 5 5
60
*/
int main(){
  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int temp = 0;
    scanf("%d", &temp);
    arr[temp]++;
  }

  for(int i = 1; i <= 100000; i++)
    sumv[i] = (sumv[i-1] + arr[i] * i) % MODULER;

  for(int i = 100000-1; i >= 1; i--){
    mulv[i] = mulv[i+1];
    if(arr[i] == 0){
      continue;
    }

    long long temp = (sumv[100000] - sumv[i]);
    if(temp < 0)
      temp += MODULER;

    mulv[i] += (temp * i * arr[i]) % MODULER;
    mulv[i] = mulv[i] % MODULER;
  }

  long long answer = 0;

  for(int i = 1; i <= 100000; i++){
    if(arr[i] == 0)
      continue;
    answer = ((i * arr[i] * mulv[i+1]) % MODULER + answer) % MODULER;
  }

  printf("%lld\n", answer);
  return 0;
}
