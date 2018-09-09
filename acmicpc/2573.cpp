#include <stdio.h>
#include <queue>
using namespace std;

int arr[302][302];
bool check[302][302];
int count = 0, check_count = 0, answer = 0;
//count -> 녹지 않은 빙하 개수

typedef struct xy{
  int x, y;
};
queue<xy> q;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      scanf("%d", &arr[i][j]);
      if(arr[i][j] > 0)
        count++;
    }
  }

  while(count > 0){ //다 녹을 때까지 반복
    for(int i = 1; i <= n; i++){
      bool c = false;
      for(int j = 1; j <= m; j++){
        if(arr[i][j] > 0){
          xy temp;
          temp.x = i; temp.y = j;
          q.push(temp);
          check[i][j] = true;
          check_count++;
          c = true;
          break;
        }
      }
      if(c)
        break;
    }

    while(!q.empty()){
      xy po = q.front(); q.pop();
      for(int i = 0; i < 4; i++){
        int newx = po.x + dir[i][0], newy = po.y + dir[i][1];

        if(arr[newx][newy] > 0 && !check[newx][newy]){
          xy newxy;
          newxy.x = newx; newxy.y = newy;
          q.push(newxy);
          check[newx][newy] = true;
          check_count++;
        }
      }
    }

    if(check_count != count){//둘 이상으로 분리됨. BFS로 연결된 개수 구함.
      break;
    }

    //빙하 녹음
    int temp[302][302];
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        temp[i][j] = arr[i][j];

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        if(arr[i][j] <= 0){
          for(int k = 0; k < 4; k++)
            temp[i + dir[k][0]][j + dir[k][1]]--;
        }
      }
    }

    count = check_count = 0; answer++;
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        arr[i][j] = temp[i][j];
        check[i][j] = false;
        if(arr[i][j] > 0){
          count++;
        }
      }
    }
  }

  if(count <= 0)
    answer = 0;
  printf("%d\n", answer);
  return 0;
}
