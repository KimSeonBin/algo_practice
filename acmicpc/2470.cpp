/*
binary search 활용.
각 num[i]의 반대값(-1을 곱한 값)을 찾는 방식으로 이분탐색을 활용
num array에 없을 경우 first, last에 가장 가까운 값을 나타낼 수 있는 index가 있다.
first, last와 주변을 비교해 0에 가장 가까운 값을 찾을 수 있다.
*/

#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n = 0;
  scanf("%d", &n);

  vector<int> num;
  int temp;
  int snum = 0, anum = 0;
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    num.push_back(temp);
    if(temp > 0){
      snum++;
    }
    else{
      anum++;
    }
  }
  sort(num.begin(), num.end());

  int mix = 2000000000;
  int answer1 = n-1, answer0 = 0;

  int first = 0, last = n-1, mid = 0, target = 0;
  for(int i = 0; i < n-1; i++){
    first = i; last = n-1;
    target = num[i] * (-1);

    while(first <= last){
      mid = (last + first) / 2;
      if(num[mid] < target){
        first = mid+1;
      }
      else if(num[mid] > target){
        last = mid-1;
      }
      else{
        answer1 = i;
        answer0 = mid;
        break;
      }
    }

    for(int j = -1; j < 2; j++){
      if(i != last+j && last+j < n && last+j >= 0){
        temp = num[i] + num[last+j];
        if(abs(temp) < mix){
          mix = abs(temp);
          answer1 = last+j;
          answer0 = i;
        }
      }
      if(i != first+j && first+j < n && first+j >= 0){
        temp = num[i] + num[first+j];
        if(abs(temp) < mix){
          mix = abs(temp);
          answer1 = first+j;
          answer0 = i;
        }
      }
    }
  }

  if(num[answer0] > num[answer1]){
    temp = answer0;
    answer0 = answer1;
    answer1 = temp;
  }
  printf("%d %d\n", num[answer0], num[answer1]);
  return 0;
}
