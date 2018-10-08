#include <cstdio>
#include <queue>
using namespace std;

typedef struct pos{
  int x, y;
};

int n = 0, m = 0;
int arr[9][9] = {0};
vector<pos> v;
queue<pos> q;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int maxv(int a, int b){
  if(a > b)
    return a;
  return b;
}

int bfs(vector<pos> vp){
  int result = 0;
  int temp[9][9] = {0};
  for(int i = 0; i < 9; i++)
    for(int j = 0; j < 9; j++)
      temp[i][j] = arr[i][j];

  for(int i = 0; i < vp.size(); i++)
    temp[vp[i].x][vp[i].y] = 1;


  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(temp[i][j] < 2)
        continue;
      pos start;
      start.x = i; start.y = j;
      q.push(start);

      while(!q.empty()){
        pos now = q.front(); q.pop();

        for(int k = 0; k < 4; k++){
          int nextx = now.x + dir[k][0], nexty = now.y + dir[k][1];
          if(nextx < 0 || nexty < 0 || nextx >= n || nexty >= m)
            continue;

          if(temp[nextx][nexty] != 0)
            continue;

          pos next;
          next.x = nextx; next.y = nexty;
          q.push(next);

          temp[next.x][next.y] = 2;
        }

      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(temp[i][j] == 0)
        result++;
    }
  }

  return result;
}

int backtracking(int preindex, vector<pos> vp){
  int result = 0;

  for(int i = preindex+1; i < v.size(); i++){
    vp.push_back(v[i]);
    if(vp.size() < 3)
      result = maxv(result, backtracking(i, vp));
    else
      result = maxv(result, bfs(vp));
    vp.pop_back();
  }
  return result;
}

int main(){
  int answer = 0;
  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &arr[i][j]);

      if(arr[i][j] == 0){
        pos temp;
        temp.x = i; temp.y = j;
        v.push_back(temp);
      }
    }
  }

  vector<pos> temp;
  answer = backtracking(-1, temp);

  printf("%d\n", answer);
  return 0;
}
