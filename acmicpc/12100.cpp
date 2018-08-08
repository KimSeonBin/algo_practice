/*
5
64 64 64 32 32
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

1번 이동 시 체크
*/

#include <stdio.h>
#include <queue>
using namespace std;
typedef struct node{
  int board[22][22];
  int count;
};

int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};//1. 위 2. 왼 3. 아 4. 오

queue<node> q;  //bfs 시도
int answer = 0;

int main(){
  int n = 0;
  scanf("%d", &n);

  node tt; tt.count = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      scanf("%d", &tt.board[i][j]);
    }
  }
  for(int i = 0; i <= n+1; i++){  //board 바깥부분은 -1로 탐색 차단
    tt.board[i][0] = -1;    tt.board[0][i] = -1;
    tt.board[n+1][i] = -1;  tt.board[i][n+1] = -1;
  }
  q.push(tt);

  while(!q.empty()){
    node t = q.front(); q.pop();

    if(t.count == 5){ //max 값 찾기
      for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
         //printf("%6d", t.board[i][j]);
          if(answer < t.board[i][j])
            answer = t.board[i][j];
        }
       // printf("\n");
      }
    //  printf("\n");
      continue;
    }

    for(int i = 0; i < 4; i++){
      //원본 값 복사 및 count 증가
      node temp;
      temp.count = t.count+1;
      for(int j = 0; j <= n+1; j++){
        for(int k = 0; k <= n+1; k++){
          temp.board[j][k] = t.board[j][k];
        }
      }

      /*
        dir -> 1. 위 2. 왼 3. 아래 4. 오른
        1. 각 방향마다 이동할 수 있는 만큼 최대한 이동시킨다.    ----------> 1. 이동
        2. 방향에 있는 블록 중 합체시킬 수 있는 블록을 합체시킨다.   ------> 2. 합체
        3. 합체 후 빈칸이 생길 수 있으므로 다시 이동할 수 있는만큼 이동.   -> 3. 재이동
       */

       if(i == 0){ // (-1, 0)
         //1. 이동
         for(int j = 1; j <= n; j++){
           int x = 0, y = 0;
           for(int k = 1; k <= n; k++){
             if(temp.board[k][j] == 0){
               continue;
             }
             x = k + dir[i][0]; y = j + dir[i][1];
             while(temp.board[x][y] == 0){
               temp.board[x][y] = temp.board[x - dir[i][0]][y - dir[i][1]];
               temp.board[x - dir[i][0]][y - dir[i][1]] = 0;
               x += dir[i][0]; y += dir[i][1];
             }
           }
         }

         //2. 합체
         for(int j = 1; j <= n; j++){
           for(int k = 1; k <= n; k++){
             if(temp.board[k][j] == 0){
               continue;
             }
             if(temp.board[k][j] == temp.board[k+dir[i][0]][j+dir[i][1]]){
               temp.board[k+dir[i][0]][j+dir[i][1]] *= 2;
               temp.board[k][j] = 0;
             }
           }
         }

         //3. 재이동
         for(int j = 1; j <= n; j++){
           int x = 0, y = 0;
           for(int k = 1; k <= n; k++){
             if(temp.board[k][j] == 0){
               continue;
             }
             x = k + dir[i][0]; y = j + dir[i][1];
             while(temp.board[x][y] == 0){
               temp.board[x][y] = temp.board[x - dir[i][0]][y - dir[i][1]];
               temp.board[x - dir[i][0]][y - dir[i][1]] = 0;
               x += dir[i][0]; y += dir[i][1];
             }
           }
         }
       }
       else if(i == 1){ //(0, -1)
         //1. 이동
         for(int j = 1; j <= n; j++){
           int x = 0, y = 0;
           for(int k = 1; k <= n; k++){
             if(temp.board[j][k] == 0){
               continue;
             }
             x = j + dir[i][0]; y = k + dir[i][1];
             while(temp.board[x][y] == 0){
               temp.board[x][y] = temp.board[x - dir[i][0]][y - dir[i][1]];
               temp.board[x - dir[i][0]][y - dir[i][1]] = 0;
               x += dir[i][0]; y += dir[i][1];
             }
           }
         }

         //2. 합체
         for(int j = 1; j <= n; j++){
           for(int k = 1; k <= n; k++){
             if(temp.board[j][k] == 0){
               continue;
             }
             if(temp.board[j][k] == temp.board[j+dir[i][0]][k+dir[i][1]]){
               temp.board[j+dir[i][0]][k+dir[i][1]] *= 2;
               temp.board[j][k] = 0;
             }
           }
         }

         //3. 재이동
         for(int j = 1; j <= n; j++){
           int x = 0, y = 0;
           for(int k = 1; k <= n; k++){
             if(temp.board[j][k] == 0){
               continue;
             }
             x = j + dir[i][0]; y = k + dir[i][1];
             while(temp.board[x][y] == 0){
               temp.board[x][y] = temp.board[x - dir[i][0]][y - dir[i][1]];
               temp.board[x - dir[i][0]][y - dir[i][1]] = 0;
               x += dir[i][0]; y += dir[i][1];
             }
           }
         }
       }
       else if(i == 2){ //(1, 0)
         //1. 이동
         for(int j = 1; j <= n; j++){
           int x = 0, y = 0;
           for(int k = n; k >= 1; k--){
             if(temp.board[k][j] == 0){
               continue;
             }
             x = k + dir[i][0]; y = j + dir[i][1];
             while(temp.board[x][y] == 0){
               temp.board[x][y] = temp.board[x - dir[i][0]][y - dir[i][1]];
               temp.board[x - dir[i][0]][y - dir[i][1]] = 0;
               x += dir[i][0]; y += dir[i][1];
             }
           }
         }

         //2. 합체
         for(int j = 1; j <= n; j++){
           for(int k = n; k >= 1; k--){
             if(temp.board[k][j] == 0){
               continue;
             }
             if(temp.board[k][j] == temp.board[k+dir[i][0]][j+dir[i][1]]){
               temp.board[k+dir[i][0]][j+dir[i][1]] *= 2;
               temp.board[k][j] = 0;
             }
           }
         }

         //3. 재이동
         for(int j = 1; j <= n; j++){
           int x = 0, y = 0;
           for(int k = n; k >= 1; k--){
             if(temp.board[k][j] == 0){
               continue;
             }
             x = k + dir[i][0]; y = j + dir[i][1];
             while(temp.board[x][y] == 0){
               temp.board[x][y] = temp.board[x - dir[i][0]][y - dir[i][1]];
               temp.board[x - dir[i][0]][y - dir[i][1]] = 0;
               x += dir[i][0]; y += dir[i][1];
             }
           }
         }
       }
       else{  //(0, 1)
         //1. 이동
         for(int j = 1; j <= n; j++){
           int x = 0, y = 0;
           for(int k = n; k >= 1; k--){
             if(temp.board[j][k] == 0){
               continue;
             }
             x = j + dir[i][0]; y = k + dir[i][1];
             while(temp.board[x][y] == 0){
               temp.board[x][y] = temp.board[x - dir[i][0]][y - dir[i][1]];
               temp.board[x - dir[i][0]][y - dir[i][1]] = 0;
               x += dir[i][0]; y += dir[i][1];
             }
           }
         }

         //2. 합체
         for(int j = 1; j <= n; j++){
           for(int k = n; k >= 1; k--){
             if(temp.board[j][k] == 0){
               continue;
             }
             if(temp.board[j][k] == temp.board[j+dir[i][0]][k+dir[i][1]]){
               temp.board[j+dir[i][0]][k+dir[i][1]] *= 2;
               temp.board[j][k] = 0;
             }
           }
         }

         //3. 재이동
         for(int j = 1; j <= n; j++){
           int x = 0, y = 0;
           for(int k = n; k >= 1; k--){
             if(temp.board[j][k] == 0){
               continue;
             }
             x = j + dir[i][0]; y = k + dir[i][1];
             while(temp.board[x][y] == 0){
               temp.board[x][y] = temp.board[x - dir[i][0]][y - dir[i][1]];
               temp.board[x - dir[i][0]][y - dir[i][1]] = 0;
               x += dir[i][0]; y += dir[i][1];
             }
           }
         }
       }

       q.push(temp);
    }
  }

  printf("%d\n", answer);

  return 0;
}
