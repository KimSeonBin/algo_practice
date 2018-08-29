#include <stdio.h>
#include <cmath>
using namespace std;

int road[102][102];

int main(){
  int n = 0, L = 0, answer = 0;
  bool check[102];

  scanf("%d %d", &n, &L);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++)
      scanf("%d", &road[i][j]);
  }

  for(int i = 1; i <= n; i++){
    //가로
    bool isable = true;

    for(int j = 1; j < n; j++){
      if(road[i][j] != road[i][j+1]){
        if(abs(road[i][j] - road[i][j+1]) > 1){
          isable = false;
          break;
        }
        if(road[i][j] > road[i][j+1]){
          for(int k = j+1; k <= j+L; k++){
            if(k > 100){
              isable = false;
              break;
            }
            if(!check[k] && road[i][j] - road[i][k] == 1){
              check[k] = true;
            }
            else{
              isable = false;
              break;
            }
          }
        }
        else{
          for(int k = j; k >= j-L+1; k--){
            if(k < 1){
              isable = false;
              break;
            }
            if(!check[k] && (road[i][j+1] - road[i][k]) == 1){
              check[k] = true;
            }
            else{
              isable = false;
              break;
            }
          }
        }
        if(!isable)
          break;
      }
    }

    if(isable)
      answer++;

    isable = true;
    for(int j = 1; j <= 100; j++){
      check[j] = false;
    }

    //세로
    for(int j = 1; j < n; j++){
      if(road[j][i] != road[j+1][i]){
        if(abs(road[j+1][i] - road[j+1][i]) > 1){
          isable = false;
          break;
        }
        if(road[j][i] > road[j+1][i]){
          for(int k = j+1; k <= j+L; k++){
            if(k > 100){
              isable = false;
              break;
            }
            if(!check[k] && road[j][i] - road[k][i] == 1){
              check[k] = true;
            }
            else{
              isable = false;
              break;
            }
          }
        }
        else{
          for(int k = j; k >= j-L+1; k--){
            if(k < 1){
              isable = false;
              break;
            }
            if(!check[k] && (road[j+1][i] - road[k][i]) == 1){
              check[k] = true;
            }
            else{
              isable = false;
              break;
            }
          }
        }
        if(!isable)
          break;
      }
    }

    if(isable)
      answer++;

    for(int j = 1; j <= 100; j++){
      check[j] = false;
    }
  }
  printf("%d\n", answer);
  return 0;
}
