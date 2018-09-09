#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
/*
two pointer 웅용


*/
int main(){
  int x = 0;
  while(scanf("%d", &x) != EOF){
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      int t = 0;
      scanf("%d", &t);
      arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    x *= 10000000;

    bool check = false;

    int s = 0, e = n-1;
    while(s < e){
      if(s < 0 || e >= n)
        break;

      int su = arr[s] + arr[e];
      if(su > x){
        e--;
      }
      else if(su < x){
        s++;
      }
      else{
        printf("yes %d %d\n", arr[s], arr[e]);
        check = true;
        break;
      }

    }

    if(!check)
      printf("danger\n");

    arr.clear();
  }
  return 0;
}
