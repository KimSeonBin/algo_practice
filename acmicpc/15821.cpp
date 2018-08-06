#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<double> arr2;

int main(){
  int n = 0, k = 0;
  scanf("%d %d", &n, &k);

  for(int i = 0; i < n; i++){
    int pointcount = 0;
    scanf("%d", &pointcount);

    long long max = 0, temp = 0;

    for(int j = 0; j < pointcount; j++){
      long long x = 0, y = 0;
      scanf("%lld %lld", &x, &y);
      temp = x*x + y*y;
      if(temp > max){
        max = temp;
      }
    }
    arr2.push_back(sqrt(max));
  }

  sort(arr2.begin(), arr2.end());
  printf("%0.2lf", arr2[k-1]*arr2[k-1]);
  return 0;
}
