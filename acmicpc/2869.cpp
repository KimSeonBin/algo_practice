#include <stdio.h>
int main(){
  int a = 0, b = 0, v = 0, ans = 0;
  scanf("%d %d %d", &a, &b ,&v);
  ans = (v-a) / (a-b) + 1;
  if((v-a) % (a-b) > 0)
    ans++;

  printf("%d\n", ans);
  return 0;
}
