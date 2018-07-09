#include <stdio.h>

int main(){
  int n = 0; int answer = 1;
  scanf("%d", &n);

  for(int i = 2; i <= n; i++){
    if(i % 2 == 0){
      answer = (answer * 2 + 1) % 10007;
    }
    else{
      answer = (answer * 2 - 1) % 10007;
    }
  }
  printf("%d", answer);
  return 0;
}
