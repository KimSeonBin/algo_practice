#include <cstdio>
#include <vector>
#include <algorithm>

#define DIRSIZE 4

using namespace std;

typedef struct pos{
  int x, y, val;
  bool operator< (pos a){
    if(val == a.val){
      if(y == a.y)
        return x < a.x;
      return y < a.y;
    }
    return val < a.val;
  }
};

vector<pos> v;
int mapp[502][502] = {0};
int dp[502][502] = {0};
int dirr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
  int n = 0;
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      scanf("%d", &mapp[i][j]);

      pos temp;
      temp.x = i; temp.y = j; temp.val = mapp[i][j];
      v.push_back(temp);
    }
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < DIRSIZE; j++){
      int nextx = v[i].x + dirr[j][0], nexty = v[i].y + dirr[j][1];

      if(v[i].val < mapp[nextx][nexty])
        dp[nextx][nexty] = max(dp[v[i].x][v[i].y] + 1, dp[nextx][nexty]);
    }
  }

  int answer = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      answer = max(answer, dp[i][j]);

  printf("%d\n", answer + 1);
  return 0;
}
