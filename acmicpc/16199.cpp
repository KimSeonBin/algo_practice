#include <cstdio>

int manYear(int b[], int c[]){
  int result = c[0] - b[0] - 1;
  if(c[1] > b[1] || (c[1] == b[1] && c[2] >= b[2]))
    result++;
  return result;
}

int countYear(int b[], int c[]){
  return c[0] - b[0] + 1;
}

int yearYear(int b[], int c[]){
  return c[0] - b[0];
}

int main(){
  int birth[3] = {0}, curr[3] = {0};
  for(int i = 0; i < 3; i++)
    scanf("%d", &birth[i]);
  for(int i = 0; i < 3; i++)
    scanf("%d", &curr[i]);

  printf("%d\n", manYear(birth, curr));
  printf("%d\n", countYear(birth, curr));
  printf("%d\n", yearYear(birth, curr));
}
