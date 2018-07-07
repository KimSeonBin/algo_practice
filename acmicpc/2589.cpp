#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

char map[51][51];
int dis[51][51] = {0};

typedef struct point{
  int x;
  int y;
};

int main(){
  int L, W = 0;
  scanf("%d %d", &L, &W);
  for(int i = 0; i < L; i++){
    for(int j = 0; j < W; j++){
      scanf(" %c", &map[i][j]);
    }
  }

  queue<point> q;
  int vec1[] = {1, 0, -1, 0};
  int vec2[] = {0, 1, 0, -1};
  int mostv = 0;
  int treasure = 0;

  for(int i = 0; i < L; i++){
    for(int j = 0; j < W; j++, mostv=0){
      if(map[i][j] == 'L'){
        point t;
        t.x = i; t.y = j;
        q.push(t);

        while(q.size() != 0){
          point temp = q.front();
          q.pop();

          for(int k = 0; k < 4; k++){
            if(k % 2 == 0 && map[temp.x+vec1[k]][temp.y] == 'L' &&
            temp.x+vec1[k] >= 0 && temp.x+vec1[k] < L && dis[temp.x+vec1[k]][temp.y] == 0){
              point temp2;
              temp2.x = temp.x+vec1[k];
              temp2.y = temp.y;
              dis[temp2.x][temp2.y] = dis[temp.x][temp.y]+1;
              q.push(temp2);
              if(treasure < dis[temp2.x][temp2.y]){
                treasure = dis[temp2.x][temp2.y];
              }
            }
            if(k % 2 == 1 && map[temp.x][temp.y+vec2[k]] == 'L' &&
            temp.y+vec2[k] >= 0 && temp.y+vec2[k] < W && dis[temp.x][temp.y+vec2[k]] == 0){
              point temp2;
              temp2.x = temp.x;
              temp2.y = temp.y+vec2[k];
              dis[temp2.x][temp2.y] = dis[temp.x][temp.y]+1;
              q.push(temp2);
              if(treasure < dis[temp2.x][temp2.y]){
                treasure = dis[temp2.x][temp2.y];
              }
            }
          }
        }
        for(int a = 0; a < L; a++){
          for(int b = 0; b < W; b++){
            dis[a][b] = 0;
          }
        }
      }
    }
  }
  printf("%d\n", treasure);
  return 0;
}
