#include <cstdio>

using namespace std;

long long dist[100002] = {0};
long long city[100002] = {0};

int main(){
  int n = 0;
  long long answer = 0;
  scanf("%d", &n);
  for(int i = 0; i < n-1; i++){
    scanf("%lld", &dist[i+1]);
    dist[i+1] += dist[i];
  }
  for(int i = 0; i < n; i++){
    scanf("%lld", &city[i]);
  }

  for(int i = 0; i < n;){
    int j = i+1;

    for(; j < n; j++){
      if(city[i] > city[j]){
        break;
      }
    }

    if(j == n){
      answer += (dist[n-1] - dist[i]) * city[i];
      break;
    }
    answer += (dist[j] - dist[i]) * city[i];
    i = j;
  }

  printf("%lld\n", answer);
  return 0;
}
