#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

vector<int> v;

int main(){
  int k = 0, n = 0;
  scanf("%d %d", &k, &n);

  for(int i = 0; i < k; i++){
    long long temp = 0;
    scanf("%lld", &temp);
    v.push_back(temp);
  }

  long long s = 0, e = (long long)INT_MAX + 1;
  while(s < e){
    long long m = (s + e) / 2, count = 0;

    for(int i = 0; i < k; i++){
      count += (v[i]) / m;
      if(count > n)
        break;
    }

    if(count >= n){
      s = m + 1;
    }
    else{
      e = m;
    }
  }

  printf("%lld\n", e-1);
  return 0;
}
