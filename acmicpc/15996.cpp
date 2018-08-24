#include <stdio.h>

int main(){
  long long n = 0, a = 0, answer = 0;
  scanf("%lld %lld", &n, &a);

  if(n == 0){
    n = 1;
  }

  long long temp = a;
  while(true){
    if(temp > n){
      break;
    }
    answer += (n / temp);
    temp *= a;
  }

  printf("%lld\n", answer);
  return 0;
}
