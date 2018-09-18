#include <stdio.h>

/*
n > 1, n % 2 == 1: ERROR
n == 1 -> x * -1 와 동일
x > 0, n > 0 -> INFINITE
*/
int main(){
  int x = 0, n = 0, count = 0;
  scanf("%d %d", &x, &n);
  if(n % 2 == 1 & n > 1){
    printf("ERROR\n");
    return 0;
  }

  if(n == 1){
    x *= -1;
    n = 0;
  }

  n /= 2;
  x -= n;
  if(n == 0 && x > 0){
    printf("INFINITE\n");
    return 0;
  }
  while(x > 0){
    count++;
    x -= n;
  }

  printf("%d\n", count);
  return 0;
}
