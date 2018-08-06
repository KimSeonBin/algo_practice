#include <stdio.h>
#include <vector>
#include <queue>
#define maxxx 9223372036854775807L
using namespace std;

typedef struct node{
  int x;
  int y;
  long long cost;
};

vector<int> x;
vector<int> y;

long long dd[2001][2001];
long long memo[2001][2001];
int count[2001][2001];
queue<node> q;
int dir[3][2] = {{-1, -1}, {-1, 0}, {0, -1}};

int main(){
  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int x1 = 0;
    scanf("%d", &x1);
    x.push_back(x1);
  }
  for(int i = 0; i < n; i++){
    int y1 = 0;
    scanf("%d", &y1);
    y.push_back(y1);
  }
  long long answer = maxxx;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      dd[i+1][j+1] = (long long)(x[i] - y[j]) * (x[i] - y[j]);
      memo[i+1][j+1] = maxxx;
      count[i][j] = 3;
      if(i == 0 || j == 0 || i == n-1 || j == n-1){
        count[i+1][j+1] = 1;
      }
    }
  }

  node t;
  t.x = t.y = n;
  t.cost = dd[n][n];
  q.push(t);

  while(!q.empty()){
    node temp = q.front();
    q.pop();
    if(temp.x == 1 && temp.y == 1){
      if(answer > temp.cost){
        answer = temp.cost;
        memo[1][1] = answer;
      }
      continue;
    }

    if(temp.x == 1){
      node temp2;
      temp2.x = temp.x; temp2.y = temp.y - 1;
      temp2.cost = temp.cost + dd[temp2.x][temp2.y];
      if(memo[temp2.x][temp2.y] > temp2.cost){
        memo[temp2.x][temp2.y] = temp2.cost;
      }
      count[temp2.x][temp2.y]--;
      if(!count[temp2.x][temp2.y]){
        temp2.cost = memo[temp2.x][temp2.y];
        q.push(temp2);
      }
    }
    else if(temp.y == 1){
      node temp2;
      temp2.x = temp.x-1; temp2.y = temp.y;
      temp2.cost = temp.cost + dd[temp2.x][temp2.y];
      if(memo[temp2.x][temp2.y] > temp2.cost){
        memo[temp2.x][temp2.y] = temp2.cost;
      }
      count[temp2.x][temp2.y]--;
      if(!count[temp2.x][temp2.y]){
        temp2.cost = memo[temp2.x][temp2.y];
        q.push(temp2);
      }
    }
    else{
      for(int i = 0; i < 3; i++){
        node temp2;
        temp2.x = temp.x + dir[i][0]; temp2.y = temp.y + dir[i][1];
        temp2.cost = temp.cost + dd[temp2.x][temp2.y];
        if(memo[temp2.x][temp2.y] > temp2.cost){
          memo[temp2.x][temp2.y] = temp2.cost;
        }
        count[temp2.x][temp2.y]--;
        if(!count[temp2.x][temp2.y]){
          temp2.cost = memo[temp2.x][temp2.y];
          q.push(temp2);
        }
      }
    }
  }

  printf("%lld\n", answer);
  return 0;
}
