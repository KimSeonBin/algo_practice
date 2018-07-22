#include <stdio.h>
#include <queue>
using namespace std;

int main(){
  int n = 0;
  scanf("%d", &n);
  queue<int> q;
  int arr[5001] = {0};

  arr[3] = 1;
  arr[5] = 1;
  q.push(3);
  q.push(5);
  int temp = 0;
  while(!q.empty()){
    temp = q.front();
    q.pop();

    if(temp + 3 < 5001 && arr[temp+3] == 0){
      arr[temp+3] = arr[temp]+1;
      q.push(temp+3);
    }
    if(temp + 5 < 5001 && arr[temp+5] == 0){
      arr[temp+5] = arr[temp]+1;
      q.push(temp+5);
    }
  }
  if(arr[n] == 0){
    arr[n] = -1;
  }
  printf("%d\n", arr[n]);
  return 0;
}
