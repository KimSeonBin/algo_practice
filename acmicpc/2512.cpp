#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> requiremoney;
  int n = 0, limit = 0, temp = 0;
  int upbound = 0, lowbound = 1, total = 0;
  int answer = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    requiremoney.push_back(temp);
    if(temp > upbound){
      upbound = temp;
    }
  }
  scanf("%d", &limit);


  int mid = 0;
  while(lowbound <= upbound){
    mid = (lowbound + upbound) / 2;
    total = 0;
    for(int i = 0; i < n; i++){
      if(requiremoney[i] < mid){
        total += requiremoney[i];
      }
      else{
        total += mid;
      }
    }

    if(total <= limit){
      lowbound = mid + 1;
      answer = mid;
    }
    else{
      upbound = mid - 1;
    }
  }
  printf("%d\n", answer);
  return 0;
}
