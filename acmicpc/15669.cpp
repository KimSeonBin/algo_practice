#include <cstdio>
#include <vector>
#include <queue>
#include <queue>
using namespace std;

typedef struct pos {
  int index, count;
};

vector<int> vec[100001];
int doublecount[100001] = {0};
bool check[100001] = {false};


int dfs(int index){
  int result = 0;
  for(int i = 0; i < vec[index].size(); i++){
    int next = vec[index][i];
    if(check[next])
      continue;
    check[next] = true;

    for(int j = 0; j < vec[next].size(); j++){
      if(check[vec[next][j]])
        continue;
      check[vec[next][j]] = true;
      result++;
      result += dfs(vec[next][j]);
    }
  }
  doublecount[index] = result;
  return result;
}

int main(){
  int n = 0, m = 0;
  scanf("%d %d", &n, &m);

  for(int i = 0; i < n-1; i++){
    int u = 0, v = 0;
    scanf("%d %d", &u, &v);

    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  check[1] = true;
  doublecount[1] = dfs(1);

  for(int i = 0; i <= 100000; i++)
    check[i] = false;
  check[2] = true;
  doublecount[2] = dfs(2);

  for(int i = 0; i < m; i++){
    int u = 0, v = 0, c = 0;
    scanf("%d %d %d", &u, &v, &c);


  }

  for(int i = 1; i <= 6; i++){
    printf("%d\n", doublecount[i]);
  }
  return 0;
}
