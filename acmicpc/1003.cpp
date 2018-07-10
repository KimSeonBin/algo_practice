#include <stdio.h>

// int fibonacci(int n){
//   if (n == 0){
//     printf("0");
//     return 0;
//   }
//   else if(n == 1){
//     printf("1");
//     return 1;
//   }
//   else{
//     return fibonacci(n-1) + fibonacci(n-2);
//   }
// }
int main(){
  int t = 0, n = 0;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    scanf(" %d", &n);
    int zero = 0, one = 1, temp = 0;
    if(n == 0){
      printf("1 0\n");
    }
    else{
      for(int j = 1; j < n; j++){
        temp = zero;
        zero = one;
        one = temp + one;
      }
      printf("%d %d\n", zero, one);
    }
  }
  return 0;
}
