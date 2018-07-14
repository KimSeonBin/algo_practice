#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct coin{
  int value;
  int amount;
  bool operator< (coin a){
    return this->value < a.value;
  }
};

int main(){
  vector<coin> wallet;
  // int pay[101][10001] = {0};
  int pay[10001] = {0};
  int temp[10001] = {0};
  int t = 0, k = 0;
  scanf("%d\n%d", &t, &k);
  int temp0 = 0, temp1 = 0;
  for(int i = 0; i < k; i++){
    scanf("%d %d", &temp0, &temp1);
    coin temp;
    temp.value = temp0; temp.amount = temp1;
    wallet.push_back(temp);
  }
  sort(wallet.begin(), wallet.end());

  int last = 0;
  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= wallet[i-1].amount; j++){
      for(int q = 1; q <= last; q++){
        if(wallet[i-1].value * j + q <= t){
          pay[wallet[i-1].value * j + q] += temp[q];
        }
      }
      if(wallet[i-1].value * j <= t){
        pay[wallet[i-1].value * j]++;
      }
    }

    last += wallet[i-1].amount * wallet[i-1].value;
    if(last > t){
      last = t;
    }
    for(int j = 1; j <= last; j++){
      if(last < 10001){
        temp[j] = pay[j];
      }
      else{
        break;
      }
    }

  }

  printf("%d\n", pay[t]);
  return 0;
}
