#include <stdio.h>
#include <queue>

using namespace std;
typedef struct pos{
  int x, y, count;
};
queue<pos> q;
queue<pos> fire;

char map[1002][1002];
int dirr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
  int t = 0;
  scanf("%d", &t);
  for(int iter = 0; iter < t; iter++){

    int n = 0, m = 0, answer = 100000000;

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
      for(int j = 1; j <= n; j++){
        scanf(" %c", &map[i][j]);
        if(map[i][j] == '@'){
          pos temp;
          temp.x = i; temp.y = j; temp.count = 0;
          q.push(temp);
        }
        if(map[i][j] == '*'){
          pos temp;
          temp.x = i; temp.y = j;
          fire.push(temp);
        }
      }
    }


    while(!q.empty()){
      int firesize = fire.size();
      for(int i = 0; i < firesize; i++){
        pos f = fire.front(); fire.pop();
        for(int j = 0; j < 4; j++){
          pos nf;
          nf.x = f.x + dirr[j][0]; nf.y = f.y + dirr[j][1];
          if(nf.x < 1 || nf.x > m || nf.y < 1 || nf.y > n)
            continue;
          if(map[nf.x][nf.y] == '*' || map[nf.x][nf.y] == '#')
            continue;
          fire.push(nf);
          map[nf.x][nf.y] = '*';
        }
      }

      int qsize = q.size();

      for(int qs = 0; qs < qsize; qs++){
        pos p = q.front(); q.pop();
        if(p.x < 1 || p.x > m || p.y < 1 || p.y > n){
          if(answer > p.count)
            answer = p.count;
          break;
        }

        for(int i = 0; i < 4; i++){
          pos newp;
          newp.x = p.x + dirr[i][0]; newp.y = p.y + dirr[i][1]; newp.count = p.count+1;
          if(map[newp.x][newp.y] == '#' || map[newp.x][newp.y] == '*' || map[newp.x][newp.y] == '?')
            continue;
          q.push(newp);
          map[newp.x][newp.y] = '?';
        }
      }

      if(answer != 100000000){
        break;
      }

    }
    if(answer == 100000000){
      printf("IMPOSSIBLE\n");
    }
    else{
      printf("%d\n", answer);
    }

    while(!q.empty()){
      q.pop();
    }
    while(!fire.empty()){
      fire.pop();
    }
    for(int i = 0; i <= m+1; i++){
      for(int j = 0; j <= n+1; j++)
        map[i][j] = '.';
    }
  }
  return 0;
}
