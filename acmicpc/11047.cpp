#include <stdio.h>

int coinv[11];

int main(){
  int n = 0, k = 0, sum = 0;
  scanf("%d %d", &n, &k);
  for(int i = 1; i <= n; i++){
    scanf("%d", &coinv[i]);
  }

  for(int i = n; i >= 1; i--){
    if(coinv[i] > k)
      continue;
    if(k == 0)
      break;
    sum += k / coinv[i];
    k -= (k / coinv[i]) * coinv[i];
  }
  printf("%d\n", sum);
  return 0;
}
