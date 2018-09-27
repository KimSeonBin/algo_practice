#include <cstdio>
#include <queue>
using namespace std;

typedef struct pos {
  int x, y, wall, dis;
};
queue<pos> q;

char map[1001][1001];
bool check[1001][1001][2];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
  int n = 0, m = 0, answer = 1000000;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf(" %c", &map[i][j]);
    }
  }

  pos start;
  start.x = 0; start.y = 0; start.wall = 1; start.dis = 1;
  check[0][0][0] = true; check[0][0][1] = true;
  q.push(start);

  while(!q.empty()){
    pos now = q.front(); q.pop();
    if(now.x == n-1 & now.y == m-1){
      if(answer > now.dis)
        answer = now.dis;
      continue;
    }

    for(int i = 0; i < 4; i++){
      int newx = now.x + dir[i][0], newy = now.y + dir[i][1];

      if(newx < 0 || newy < 0 || newx >= n || newy >= m)
        continue;

      pos next;
      next.x = newx; next.y = newy; next.dis = now.dis + 1; next.wall = now.wall;
      if(map[newx][newy] == '1'){
        next.wall--;
        if(next.wall < 0)
          continue;
      }

      if(check[next.x][next.y][next.wall])
        continue;

      if(next.wall == 1)
        check[next.x][next.y][1] = true;
      check[next.x][next.y][0] = true;


      q.push(next);
    }
  }

  if(answer == 1000000)
    answer = -1;

  printf("%d\n", answer);
  return 0;
}
