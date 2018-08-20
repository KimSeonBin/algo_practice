#include <stdio.h>
#include <string.h>

char room[102][102];

int main(){
  int n = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf(" %s", &room[i]);
  }

  int rowanswer = 0, colanswer = 0;
  for(int i = 0; i < n; i++){
    //가로로 눕기
    int start = -1, end = -1;
    for(int j = 0; j < n; j++){
      if(room[i][j] == 'X'){
        if((end-start) >= 2){
          rowanswer++;
        }
        start = end = j;
      }
      else{
        end = j;
      }
    }
    if((end-start) >= 2){
      rowanswer++;
    }

    //세로로 눕기
    start = end = -1;
    for(int j = 0; j < n; j++){
      if(room[j][i] == 'X'){
        if((end-start) >= 2){
          colanswer++;
        }
        start = end = j;
      }
      else{
        end = j;
      }
    }
    if((end-start) >= 2){
      colanswer++;
    }
  }

  printf("%d %d\n", rowanswer, colanswer);
  return 0;
}
