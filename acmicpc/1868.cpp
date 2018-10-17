#include <cstdio>
#include <vector>

using namespace std;

typedef struct node{
  int s, e, t;
};

vector<node> allroad;

int main(){
  int t = 0, INF = 100000000;
  scanf("%d", &t);
  for(int it = 0; it < t; it++){
    int n = 0, m = 0, w = 0;
    scanf("%d %d %d", &n, &m, &w);

    int roadtemp[501][501] = {0};
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        roadtemp[i][j] = INF;

    for(int i = 0; i < m; i++){
      int t1, t2, t3;
      scanf("%d %d %d", &t1, &t2, &t3);
      if(roadtemp[t1][t2] > t3){
        roadtemp[t1][t2] = t3;
        roadtemp[t2][t1] = t3;
      }
    }

    for(int i = 0; i < w; i++){
      int t1, t2, t3;
      scanf("%d %d %d", &t1, &t2, &t3);
      if(roadtemp[t1][t2] > -t3){
        roadtemp[t1][t2] = -t3;
      }
    }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(roadtemp[i][j] != INF){
          node nd;
          nd.s = i; nd.e = j; nd.t = roadtemp[i][j];
          allroad.push_back(nd);
        }
      }
    }

    int dis[502] = {0};
    for(int i = 1; i <= n; i++)
      dis[i] = INF;
    dis[1] = 0;

    for(int i = 1; i < n; i++){
      for(int j = 0; j < allroad.size(); j++){
        if(dis[allroad[j].s] != INF && dis[allroad[j].e] > dis[allroad[j].s] + allroad[j].t){
          dis[allroad[j].e] = dis[allroad[j].s] + allroad[j].t;
        }
      }
    }
    bool check = false;

    for(int j = 0; j < allroad.size(); j++){
      if(dis[allroad[j].s] != INF && dis[allroad[j].e] > dis[allroad[j].s] + allroad[j].t){
        check = true;
        break;
      }
    }

    if(check)
      printf("YES\n");
    else
      printf("NO\n");

    allroad.clear();
  }

  return 0;
}
