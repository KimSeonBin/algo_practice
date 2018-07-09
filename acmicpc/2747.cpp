#include <stdio.h>
#include <vector>
using namespace std;


int main(){
  vector<long long> v;
  int n = 0;
  scanf("%d", &n);
  v.push_back((long long)0);
  v.push_back((long long)1);

  for(int i = 1; i < n; i++){
    v.push_back(v[i] + v[i-1]);
  }
  printf("%lld\n", v[n]);

  return 0;
}
