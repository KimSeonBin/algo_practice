#include <stdio.h>
#include <string.h>
#define maxx(a, b) ((a) > (b) ? (a) : (b))
#define minn(a, b) ((a) < (b) ? (a) : (b))

int direct[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; //0.남 1.동 2.북 3.서
int square[2][2] = {{199, 200}, {199, 200}};//0.왼위 1.오아
int mypos[2] = {199, 200};

int changeDirection(int direction, char turn){
  direction += 4;
  if(turn == 'L'){
    direction++;
  }
  else{
    direction--;
  }
  return direction % 4;
}

char map[401][401];

int main(){
  int n = 0;
  char sent[52];
  scanf("%d", &n);
  scanf(" %s", sent);

  for(int i = 0; i < 401; i++)
    for(int j = 0; j < 401; j++)
      map[i][j] = '#';
  map[mypos[0]][mypos[1]] = '.';

  int direction = 0;
  for(int i = 0; i < n; i++){
    if(sent[i] == 'F'){
      if(direction == 0){
        mypos[0]++;
      }
      else if(direction == 1){
        mypos[1]++;
      }
      else if(direction == 2){
        mypos[0]--;
      }
      else if(direction == 3){
        mypos[1]--;
      }

      map[mypos[0]][mypos[1]] = '.';
      square[0][0] = minn(square[0][0], mypos[0]);
      square[0][1] = minn(square[0][1], mypos[1]);
      square[1][0] = maxx(square[1][0], mypos[0]);
      square[1][1] = maxx(square[1][1], mypos[1]);
    }
    else{
      direction = changeDirection(direction, sent[i]);
    }
  }

  for(int i = square[0][0]; i <= square[1][0]; i++){
    for(int j = square[0][1]; j <= square[1][1]; j++){
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
  return 0;
}
