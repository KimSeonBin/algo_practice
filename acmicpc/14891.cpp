#include <stdio.h>
#include <string.h>

/*
1번째 톱니바퀴
2번 접점: wheel[1][2]

2번째 톱니바퀴
1번 접점: wheel[2][6] 3번 접점: wheel[2][2]

3번째 톱니바퀴
2번 접점: wheel[3][6] 4번 접점: wheel[3][2]

4번째 톱니바퀴
3번 접점: wheel[4][6]

*/

char wheel[5][10];
int howturn[5];

void moveCounterClockwise(int ori){
  char temp = wheel[ori][0];
  for(int i = 1; i < 8; i++)
    wheel[ori][i-1] = wheel[ori][i];

  wheel[ori][7] = temp;
}

void moveClockwise(int ori){
  char temp = wheel[ori][7];
  for(int i = 6; i >= 0; i--)
    wheel[ori][i+1] = wheel[ori][i];

  wheel[ori][0] = temp;
}

void RighttoLeft(int ori, int dir){
  if(ori < 2 || ori > 4)
    return;
  if(wheel[ori][6] == wheel[ori-1][2])
    return;

  dir *= -1;
  howturn[ori-1] = dir;
  RighttoLeft(ori-1, dir);
}

void LefttoRight(int ori, int dir){
  if(ori < 1 || ori > 3)
    return;
  if(wheel[ori][2] == wheel[ori+1][6])
    return;

  dir *= -1;
  howturn[ori+1] = dir;
  LefttoRight(ori+1, dir);
}

int getScore(){
  int temp = 1, result = 0;
  for(int i = 1; i <= 4; i++){
    if(wheel[i][0] == '1')
      result += temp;
    temp *= 2;
  }

  return result;
}

int main(){
  for(int i = 1; i <= 4; i++){
    scanf(" %s", wheel[i]);
  }

  int k = 0;
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    int wnum = 0, dir = 0;
    scanf("%d %d", &wnum, &dir);

    RighttoLeft(wnum, dir);
    LefttoRight(wnum, dir);
    howturn[wnum] = dir;

    for(int j = 1; j <= 4; j++){
      if(howturn[j] == 1){
        moveClockwise(j);
      }
      else if(howturn[j] == -1){
        moveCounterClockwise(j);
      }
      howturn[j] = 0;
    }
  }

  printf("%d\n", getScore());
  return 0;
}
