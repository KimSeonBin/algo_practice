/*
최대 거리가 c 이상인가?
최대 거리가 c 이하인가?
이것을 가지고 이분탐식을 시도한다.
*/

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n = 0, c = 0, temp = 0;
  vector<int> iptime;
  int start = 0, end = 0, mid = 0;
  int starttemp = 0;
  int answer = 1000000001;
  int count = 0;

  scanf("%d %d", &n, &c);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    iptime.push_back(temp);
  }
  sort(iptime.begin(), iptime.end());

  start = 1; end = iptime[n-1]-iptime[0];

  while(start <= end){
    count = 1;
    mid = (start + end) / 2;
    starttemp = 0;
    for(int i = 0; i < n; i++){
      if(iptime[i] - iptime[starttemp] >= mid){
        count++;
        starttemp = i;
      }
    }

    if(count >= c){
      start = mid + 1;
      answer = mid;
    }
    else if(count < c){
      end = mid - 1;
    }
  }

  printf("%d\n", answer);
  return 0;
}
