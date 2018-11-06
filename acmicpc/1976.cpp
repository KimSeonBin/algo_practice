#include <cstdio>
#include <vector>

using namespace std;

int citymap[201][201];
int plan[2001];

void setCitymapFullConect(int n){
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        if(citymap[i][k] == 1 && citymap[k][j])
          citymap[i][j] = 1;
}

bool getResult(int m){
  bool result = true;

  for(int i = 0; i < m-1; i++){
    if(citymap[plan[i]-1][plan[i+1]-1] == 0){
      result = false;
      break;
    }
  }
  return result;
}

int main(){
  int n = 0, m = 0;
  scanf("%d", &n);
  scanf("%d", &m);

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &citymap[i][j]);
    }
    citymap[i][i] = 1;
  }

  for(int i = 0; i < m; i++)
    scanf("%d", &plan[i]);

  setCitymapFullConect(n);

  if(getResult(m))
    printf("YES\n");
  else
    printf("NO\n");

  return 0;
}
