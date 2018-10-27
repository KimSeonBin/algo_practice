#include <cstdio>

int cases[81] = {0};

int main(){
  int s1 = 0, s2 = 0, s3 = 0;
  scanf("%d %d %d", &s1, &s2, &s3);

  for(int i = 1; i <= s1; i++)
    for(int j = 1; j <= s2; j++)
      for(int k = 1; k <= s3; k++)
        cases[i+j+k]++;

  int answer = 0, temp = 0;
  for(int i = 1; i < 81; i++){
    if(cases[i] > temp){
      answer = i;
      temp = cases[i];
    }
  }

  printf("%d\n", answer);
  return 0;
}
