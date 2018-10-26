#include <cstdio>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct tree{
  int x, y, age;
  bool operator<(tree a){
    if(age == a.age){
      if(y == a.y)
        return x < a.x;
      return y < a.y;
    }
    return age > a.age;
  }
};

int ground[11][11] = {0};
int bonus[11][11] = {0};
int deleteindex[11][11] = {0};

deque<tree> dq[11][11];
vector<tree> v;

int dirr[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0, 1}, {1,-1}, {1,0}, {1, 1}};

void doSpring(int n){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int dqsize = dq[i][j].size();
      for(int k = dqsize-1; k >= 0; k--){
        if(ground[i][j] - dq[i][j][k].age >= 0){
          ground[i][j] -= dq[i][j][k].age;
          dq[i][j][k].age++;
        }
        else{
          deleteindex[i][j] = k + 1;
          break;
        }
      }
    }
  }
}

void doSummber(int n){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      while(deleteindex[i][j] > 0){
        tree temp = dq[i][j].front();
        dq[i][j].pop_front();
        ground[i][j] += temp.age / 2;
        deleteindex[i][j]--;
      }
    }
  }
}

void doFall(int n){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      for(int q = 0; q < dq[i][j].size(); q++){
        if(dq[i][j][q].age % 5 != 0)
          continue;

        for(int k = 0; k < 8; k++){
          int nx = i + dirr[k][0], ny = j + dirr[k][1];
          if(nx < 1 || ny < 1 || nx > n || ny > n)
            continue;

          tree newtree;
          newtree.x = nx; newtree.y = ny; newtree.age = 1;
          dq[nx][ny].push_back(newtree);
        }
      }
    }
  }
}

void doWinter(int n){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      ground[i][j] += bonus[i][j];
    }
  }
}

int getAnswer(int n){
  int result = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      result += dq[i][j].size();
    }
  }
  return result;
}

int main(){
  int n = 0, m = 0, k = 0;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      ground[i][j] = 5;
      scanf("%d", &bonus[i][j]);
    }
  }

  for(int i = 0; i < m; i++){
    tree temp;
    scanf("%d %d %d", &temp.x, &temp.y, &temp.age);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < m; i++){
    dq[v[i].x][v[i].y].push_back(v[i]);
  }

  for(int i = 0; i < k; i++){
    doSpring(n);
    doSummber(n);
    doFall(n);
    doWinter(n);
  }

  printf("%d\n", getAnswer(n));
  return 0;
}
