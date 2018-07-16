#include <stdio.h>
#include <vector>
using namespace std;
#include <queue>

typedef struct knight{
  int x;
  int y;
  int count;
};

int main(){
  int t = 0;
  scanf("%d", &t);

  int move[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
  int boardsize = 0;
  int startx = 0, starty = 0;
  int destx = 0, desty = 0;
  for(int iter = 0; iter < t; iter++){
    queue<knight> bfs;

    scanf("%d", &boardsize);
    scanf("%d %d", &startx, &starty);
    scanf("%d %d", &destx, &desty);

    knight ss;
    ss.x = startx; ss.y = starty; ss.count = 0;
    bfs.push(ss);

    bool check[300][300] = {false};
    check[startx][starty] = true;

    while(!bfs.empty()){
      knight temp = bfs.front();
      bfs.pop();
      if(temp.x == destx && temp.y == desty){
        printf("%d\n", temp.count);
        break;
      }

      for(int i = 0; i < 8; i++){
        knight temp2;
        temp2.x = temp.x + move[i][0];
        temp2.y = temp.y + move[i][1];
        if(temp2.x >= 0 && temp2.x < boardsize){
          if(temp2.y >= 0 && temp2.y < boardsize){
            if(check[temp2.x][temp2.y] == false){
              temp2.count = temp.count + 1;
              bfs.push(temp2);
              check[temp2.x][temp2.y] = true;
            }
          }
        }
      }
    }
  }
  return 0;
}
