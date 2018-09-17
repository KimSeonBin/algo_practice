#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


/*
http://jason9319.tistory.com/98

Strongly Connected Component

Kosaraju's Algorithm

1. 그래프와 원래 그래프의 역순으로 된 역그래프를 구한다.
2. 그래프를 DFS로 탐색, 더 이상 탐색할 선분이 없는 정점을 저장.
3. 모든 탐색을 끝나면 DFS 결과를 저장한 array를 역순으로 바꿈
4. 3번 array순으로 역그래프에서 DFS 탐색. 한 정점에서 시작해 끝나는 점까지가 SCC

*/

vector<vector<int>> scc;
vector<int> arr[10001];
vector<int> backarr[10001];

vector<int> backresult;
vector<int> s_result;
stack<int> s;
bool check[10001];

void DFS(int index){
  check[index] = true;  //중복 탐색 방지
  for(int i = 0; i < arr[index].size(); i++){
    if(check[arr[index][i]])
      continue;
    DFS(arr[index][i]);
  }
  s_result.push_back(index); // 더 이상 탐색할 점이 없으면 결과에 입력
}

void reverseDFS(int index, int n){
  scc[n].push_back(index);  //탐색점은 SCC에 넣는다
  check[index] = true;
  for(int i = 0; i < backarr[index].size(); i++){
    if(check[backarr[index][i]])
      continue;
    reverseDFS(backarr[index][i], n);
  }
}


int main(){
  int v = 0, e = 0;
  scanf("%d %d", &v, &e);
  for(int i = 0; i < e; i++){
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    arr[a].push_back(b);//방향 그래프
    backarr[b].push_back(a);//역방향 그래프
  }

  for(int i = 1; i <= v; i++){
    if(check[i])
      continue;
    DFS(i);
  }

  for(int i = 1; i <= v; i++)
    check[i] = false;

  for(int i = v-1; i > -1; i--){
    int cur = s_result[i];
    if(check[cur])
      continue;
    vector<int> temp;
    scc.push_back(temp);
    reverseDFS(cur, scc.size()-1);
  }

  for(int i = 0; i < scc.size(); i++)
    sort(scc[i].begin(), scc[i].end());
  sort(scc.begin(), scc.end());

  printf("%d\n", scc.size());
  for(int i = 0; i < scc.size(); i++){
    for(int j = 0; j < scc[i].size(); j++){
      printf("%d ", scc[i][j]);
    }
    printf("-1\n");
  }

  return 0;
}
