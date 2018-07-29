#include <stdio.h>
/*
 1: 상
 2: 창
 3: 상
 4: 창
 */
int main(){
  int n = 0;
  scanf("%d", &n);


  if(n % 2 == 1){
    printf("CY\n");
  }
  else{
    printf("SK\n");
  }

  return 0;
}
