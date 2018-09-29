#include <stdio.h>

int main(){
  int answer = 1;
  int a = 0, b = 0, c = 0;
  scanf("%d %d %d", &a, &b, &c);

  int a1 = 1, b1 = 1, c1 = 1;
  while(true){
    if(a == a1 & b == b1 & c == c1){
      break;
    }
    a1++; b1++; c1++; answer++;
    if(a1 > 15)
      a1 = 1;
    if(b1 > 28)
      b1 = 1;
    if(c1 > 19)
      c1 = 1;
  }

  printf("%d\n", answer);
  return 0;
}
