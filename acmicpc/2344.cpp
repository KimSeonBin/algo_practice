#include <cstdio>

int arr[1002][1002] = {0};
int dirr[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int reflectLight(int direction){
  return (direction + 2) % 4;
}

int getHole(int x, int y, int borderx, int bordery){
  int result = 0;
  if(y == 0)
    return result + x;
  result += borderx;

  if(x == borderx+1)
    return result + y;
  result += bordery;

  if(y == bordery+1)
    return result + (borderx + 1 - x);
  result += borderx;

  return result + (bordery + 1 - y);
}

void shotLight(int n, int x, int y, int direction, int borderx, int bordery){
  do{
    x += dirr[direction][0];
    y += dirr[direction][1];

    if(arr[x][y] == 1)
      direction = reflectLight(direction);

  } while(x >= 1 && y >= 1 && x <= borderx && y <= bordery);
  printf("%d ", getHole(x, y, borderx, bordery));
}

int main(){
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      scanf("%d", &arr[i][j]);

  for(int i = 1; i <= n; i++)
    shotLight(n, i, 0, 0, n, m);
  for(int i = 1; i <= m; i++)
    shotLight(m, n+1, i, 2, n, m);
  for(int i = n; i >= 1; i--)
    shotLight(n, i, m+1, 1, n, m);
  for(int i = m; i >= 1; i--)
    shotLight(m, 0, i, 3, n, m);

  printf("\n");
  return 0;
}
