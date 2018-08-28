#include <stdio.h>
#define MAX_START 9
#define MIN_START 0
char sig[11];

bool iscorrect(int sigindex, int a, int b){
  if(sig[sigindex] == '<'){
    if(a < b)
      return true;
    return false;
  }
  else{
    if(a > b)
      return true;
    return false;
  }
}

void make_maxsig(int n){
  int answer[11];
  answer[0] = MAX_START;
  for(int i = 0; i < n; i++){
    answer[i+1] = MAX_START-(i+1);
    for(int j = i; j >= 0; j--){
      if(!iscorrect(j, answer[j], answer[j+1])){
        int temp = answer[j+1];
        answer[j+1] = answer[j];
        answer[j] = temp;
      }
      else{
        break;
      }
    }
  }

  for(int i = 0; i <= n; i++){
    printf("%d", answer[i]);
  }
  printf("\n");
}

void make_minsig(int n){
  int answer[11];
  answer[0] = MIN_START;
  for(int i = 0; i < n; i++){
    answer[i+1] = i+1;
    for(int j = i; j >= 0; j--){
      if(!iscorrect(j, answer[j], answer[j+1])){
        int temp = answer[j+1];
        answer[j+1] = answer[j];
        answer[j] = temp;
      }
      else{
        break;
      }
    }
  }

  for(int i = 0; i <= n; i++){
    printf("%d", answer[i]);
  }
  printf("\n");
}

int main(){
  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf(" %c", &sig[i]);
  }

  make_maxsig(n);
  make_minsig(n);
}
