#include <cstdio>

using namespace std;

int peo[11] = {0};
int answer[11] = {0};

int main(){
  int n = 0;
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%d", &peo[i]);
  }

  for(int i = 1; i <= n; i++){
    int j = 1, count = 0;
    while(count < peo[i]){
      if(answer[j] >= 0){
        if(answer[j] == 0)
          count++;
        j++;
      }
    }

    for(; j <= n; j++){
      if(answer[j] == 0){
        answer[j] = i;
        break;
      }
    }
  }

  for(int i = 1; i <= n; i++){
    printf("%d ", answer[i]);
  }

  return 0;
}
