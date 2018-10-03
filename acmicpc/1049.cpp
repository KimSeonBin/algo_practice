#include <stdio.h>

int min(int a, int b){
  if(a < b)
    return a;
  return b;
}

int main(){
  int n = 0, m = 0, answer = 0;
  scanf("%d %d", &n, &m);

  int a = 1001, b = 1001;

  for(int i = 0; i < m; i++){
    int ta = 0, tb = 0;
    scanf("%d %d", &ta, &tb);
    if(a > ta)
      a = ta;
    if(b > tb)
      b = tb;
  }

  answer = (n/6) * min(a, b*6);

  n = n % 6;
  answer += min(a, n * b);
  printf("%d\n", answer);

  return 0;
}
