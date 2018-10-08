#include <cstdio>
#include <vector>
using namespace std;

int arr[1001] = {0};
int tracing[1001] = {0};
int rtracing[1001] = {0};
vector<int> stk;

int search(int target){
  int s = 0, e = stk.size(), m = 0;
  while(s < e){
    m = (s+e) / 2;
    if(stk[m] < target){
      s = m + 1;
    }
    else{
      e = m;
    }
  }
  return s;
}

int maxv(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main() {
  int n = 0;
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    scanf("%d", &arr[i]);
  }

  stk.push_back(-1);
  for(int i = 1; i <= n; i++){
    int index = search(arr[i]);

    if(index == stk.size()){
      stk.push_back(arr[i]);
    }
    else{
      stk[index] = arr[i];
    }
    tracing[i] = index;
  }

  stk.clear();
  stk.push_back(-1);

  for(int i = n; i >= 1; i--){
    int index = search(arr[i]);
    if(index == stk.size()){
      stk.push_back(arr[i]);
    }
    else{
      stk[index] = arr[i];
    }
    rtracing[i] = index;
  }

  int answer = 0;
  for(int i = 1; i <= n; i++){
    answer = max(answer, tracing[i] + rtracing[i] - 1);
  }

  printf("%d\n", answer);
  return 0;
}
