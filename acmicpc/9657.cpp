#include <stdio.h>
/*

마지막 돌(n)을 가져가면 이긴다.
n-1  돌을 가져가면 진다.
n-2  돌을 가져가면 이긴다.
n-3  돌을 가져가면 진다.
n-4  돌을 가져가면 진다.
n-5  돌을 가져가면 진다. (?, 3, 1, 1)
n-6  돌을 가져가면 진다.
n-7  돌을 가져가면 이긴다.
n-8  돌을 가져가면 진다.
n-9  돌을 가져가면 이긴다.
n-10 돌을 가져가면 진다.

 */
int main(){
  int n = 0;
  bool answer = false;
  int check[3] = {1, 3, 4};
  scanf("%d", &n);

  while(n >= 0){
    if(answer){
      break;
    }
    for(int i = 0; i < 3; i++){
      if(n - check[i] == 0){
        answer = true;
        break;
      }
    }
    n -= 2;

    for(int i = 0; i < 3; i++){
      if(n - check[i] == 0){
        answer = true;
        break;
      }
    }
    n -= 5;
  }
  if(answer){
    printf("SK\n");
  }
  else{
    printf("CY\n");
  }

  return 0;
}
