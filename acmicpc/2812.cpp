#include <cstdio>

char str[500001];
char answer[500001];
int count = 0;

void setAnswer(int s, int e){
  if(count == 0)
    return;

  int index = -1;
  for(char iter = '9'; iter >= '0' && index < 0; iter--){
    for(int i = s + 1; i < e; i++){
      if(str[i] == iter){
        index = i;

        answer[index] = iter;
        count--;
        break;
      }
    }
  }

  if(index == -1)
    return;
  
  setAnswer(index, e);
  setAnswer(s, index);
}

int main(){
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf(" %c", &str[i]);
    answer[i] = 'a';
  }

  count = n - m;

  setAnswer(-1, n);

  for(int i = 0; i < n; i++)
    if(answer[i] != 'a')
      printf("%c", answer[i]);
  printf("\n");
  return 0;
}
