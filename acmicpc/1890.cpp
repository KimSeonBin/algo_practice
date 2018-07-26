#include <stdio.h>

int main(){
  int n = 0;
  scanf("%d", &n);

  int board[101][101] = {0};
  long long boardcheck[101][101] = {0};
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &board[i][j]);
    }
  }

  boardcheck[0][0]++;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == n-1 && j == n-1){
        break;
      }
      if(boardcheck[i][j] > 0){
        if(board[i][j] + i < n){
          boardcheck[i+board[i][j]][j] += boardcheck[i][j];
        }
        if(board[i][j] + j < n){
          boardcheck[i][j+board[i][j]] += boardcheck[i][j];
        }
      }
    }
  }

  printf("%lld\n", boardcheck[n-1][n-1]);

  return 0;
}
