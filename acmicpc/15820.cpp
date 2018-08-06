#include <stdio.h>

int main(){
  int s1 = 0, s2 = 0;
  scanf("%d %d", &s1, &s2);
  int answer = 0;

  for(int i = 0; i < s1; i++){
    int ta = 0, ma = 0;
    scanf("%d %d", &ta, &ma);
    if(ta != ma){
      answer = 1;
    }
  }
  for(int i = 0; i < s2; i++){
    int sa = 0, ma = 0;
    scanf("%d %d", &sa, &ma);
    if(answer == 1)
      continue;
    if(sa != ma){
      answer = 2;
    }
  }


  if(answer == 0){
    printf("Accepted\n");
  }
  else if(answer == 1){
    printf("Wrong Answer\n");
  }
  else{
    printf("Why Wrong!!!\n");
  }
  return 0;
}
