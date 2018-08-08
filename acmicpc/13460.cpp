#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

char matrix[11][11];
bool check[11][11][11][11];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
typedef struct pos{
  int rx; int ry;
  int bx; int by;
  int count;
};

queue<pos> q;
int ox = 0, oy = 0;

int main(){
  pos ori; ori.count = 0;
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    char temp[12];
    scanf(" %s", temp);
    for(int j = 1; j <= m; j++){
      matrix[i][j] = temp[j-1];
      if(temp[j-1] == 'R'){
        ori.rx = i; ori.ry = j;
      }
      else if(temp[j-1] == 'B'){
        ori.bx = i; ori.by = j;
      }
      else if(temp[j-1] == 'O'){
        ox = i; oy = j;
      }
    }
  }

  q.push(ori);
  check[ori.rx][ori.ry][ori.bx][ori.by] = true;

  while(!q.empty()){
    pos p = q.front(); q.pop();
    //printf("(%d %d) (%d %d) %d\n", p.rx, p.ry, p.bx, p.by, p.count);
    if(p.rx == ox && p.ry == oy){
      if(p.count <= 10){
        printf("%d\n", p.count);
        return 0;
      }
      else{
        break;
      }
    }

    for(int i = 0; i < 4; i++){
      bool notgor = false, notgob = false, dontpush = false;
      bool changer = false, changeb = false;
      char orir = '.', orib = '.';
      pos temp;
      temp.rx = p.rx; temp.ry = p.ry;
      temp.bx = p.bx; temp.by = p.by;
      temp.count = p.count + 1;
      while(!notgor || !notgob){
        temp.rx += dir[i][0]; temp.ry += dir[i][1];
        /*
        지켜봐야 할 것.
        1. O
        2. #
        3. R, B 충돌
        */
        if(temp.rx == ox && temp.ry == oy){
          while(true){
            temp.bx += dir[i][0]; temp.by += dir[i][1];
            if(matrix[temp.bx][temp.by] == '#'){
              temp.bx -= dir[i][0]; temp.by -= dir[i][1];
              break;
            }
            else if(temp.bx == ox && temp.by == oy){
              dontpush = true;
              break;
            }
            else{
              continue;
            }
          }
          break;
        }
        if(matrix[temp.rx][temp.ry] == '#'){
          notgor = true;
          temp.rx -= dir[i][0]; temp.ry -= dir[i][1];
          if(!changer)
            orir = matrix[temp.rx][temp.ry];
          changer = true;
          matrix[temp.rx][temp.ry] = '#'; //R, B가 겹치는 현상 방지
        }
        if(temp.rx == temp.bx && temp.ry == temp.by){
          temp.rx -= dir[i][0]; temp.ry -= dir[i][1];
        }

        temp.bx += dir[i][0]; temp.by += dir[i][1];
        if(temp.bx == ox && temp.by == oy){
          dontpush = true;
          break;
        }
        if(matrix[temp.bx][temp.by] == '#'){
          notgob = true;
          temp.bx -= dir[i][0]; temp.by -= dir[i][1];
          if(!changeb)
            orib = matrix[temp.bx][temp.by];
          changeb = true;
          matrix[temp.bx][temp.by] = '#';
        }
        if(temp.rx == temp.bx && temp.ry == temp.by){
          temp.bx -= dir[i][0]; temp.by -= dir[i][1];
        }
      }

      if(notgor)
        matrix[temp.rx][temp.ry] = orir;
      if(notgob)
        matrix[temp.bx][temp.by] = orib;

      if(dontpush) // 움직이지 않았다. B가 O에 먼저 골인. R, B가 동시에 골인
        continue;
      if(!check[temp.rx][temp.ry][temp.bx][temp.by]){
        check[temp.rx][temp.ry][temp.bx][temp.by] = true;
        //printf("(%d %d) (%d %d) -> (%d %d) (%d %d) %d\n", p.rx, p.ry, p.bx, p.by, temp.rx, temp.ry, temp.bx, temp.by, p.count);
        q.push(temp);
      }
    }
  }

  //
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= m; j++){
  //     printf("%c", matrix[i][j]);
  //   }
  //   printf("\n");
  // }

  printf("-1\n");
  return 0;
}
