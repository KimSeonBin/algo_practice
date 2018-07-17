#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> up;
  vector<int> down;
  int n = 0, h = 0;
  int temp = 0;
  int answer = 2000000000, answer_h = 0;

  scanf("%d %d", &n, &h);
  for(int i = 1; i <= n; i++){
    scanf("%d", &temp);
    if(i % 2 == 1){
      down.push_back(temp);
    }
    else{
      up.push_back(temp);
    }
  }

  sort(down.begin(), down.end());
  sort(up.begin(), up.end());

  for(int i = 1; i <= h; i++){
    int left = 0, right = 0, mid = 0;
    int sum = 0;

    //down lowerbound를 구해서 down.size와 뺀다.
    right = down.size();
    while(left < right){
      mid = (left+right)/2;
      if(down[mid] < i){
        left = mid+1;
      }
      else{
        right = mid;
      }
    }
    sum += (down.size() - right);

    //up (h) - ((n-i)의 upper bound)
    left = 0; right = up.size();
    while(left < right){
      mid = (left+right)/2;
      if(up[mid] <= h-i){
        left = mid + 1;
      }
      else{
        right = mid;
      }
    }
    sum += (up.size() - right);
    
    if(sum < answer){
      answer = sum;
      answer_h = 1;
    }
    else if(sum == answer){
      answer_h++;
    }

  }
  printf("%d %d\n", answer, answer_h);
  return 0;
}
