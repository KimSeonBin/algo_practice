#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int min(int a, int b){
  if(a > b){
    return b;
  }
  else{
    return a;
  }
}

int main(){
  int n = 0, k = 0, temp = 0, notselect = 1111111111;
  vector<int> coin;
  int answer[10001] = {0};
  int atemp[10001] = {0};
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    // if(temp > 10000){
    //   continue;
    // }
    coin.push_back(temp);
  }
  sort(coin.begin(), coin.end());

  for(int i = 1; i <= k; i++){
    answer[i] = notselect;
  }

  for(int i = 0; i < n; i++){
    if(coin[i] > 10000){
      continue;
    }
    answer[coin[i]] = 1;
    for(int j = 1; j <= k; j++){
      if(answer[j] != notselect && j+coin[i] < 10001){
        answer[j+coin[i]] = min(answer[j+coin[i]], answer[j]+1);
      }
    }
  }

  if (answer[k] == notselect) {
    printf("-1\n");
  }
  else{
    printf("%d\n", answer[k]);
  }
  return 0;
}
