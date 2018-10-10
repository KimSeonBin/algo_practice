#include <cstdio>

using namespace std;

bool hate[201][201] = {false};

int main(){
  int n = 0, m = 0, answer = 0;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++){
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    hate[a][b] = true;
    hate[b][a] = true;
  }

  for(int i = 1; i <= n; i++){
    for(int j = i+1; j <= n; j++){
      for(int k = j+1; k <= n; k++){
        if(hate[i][j] || hate[j][k] || hate[k][i])
          continue;
        answer++;
      }
    }
  }
  printf("%d\n", answer);
  return 0;
}
