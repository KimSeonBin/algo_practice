#include <stdio.h>

int a[1000001];
int main(){
  int n = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &a[i]);
  }

  int b = 0, c = 0;
  scanf("%d %d", &b ,&c);

  long long answer = 0;
  for(int i = 1; i <= n; i++){
    a[i] -= b;
  }
  answer += n;
  for(int i = 1; i <= n; i++){
    if(a[i] <= 0)
      continue;
    answer += (long long)(a[i] / c);
    if(a[i] % c != 0)
      answer++;
  }
  printf("%lld\n", answer);
  return 0;
}
