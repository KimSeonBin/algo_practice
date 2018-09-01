#include <stdio.h>
#include <cmath>
long long segtree[8400000];
long long oritree[8400000];

long long maxx(long long a, long long b){
  if(a > b)
    return a;
  return b;
}

int main(){
  int k = 0, starti = 0, howmany = 0;
  scanf("%d", &k);
  starti = pow(2, k); howmany = starti * 2 - 2;

  for(int i = 0; i < howmany; i++){
    scanf("%lld", &oritree[i+2]);
    segtree[i+2] = oritree[i+2];
  }

  for(int i = starti; i > 1; i /= 2){
    for(int j = i; j < i*2; j += 2){
      long long whobig = maxx(segtree[j], segtree[j+1]);
      segtree[j/2] += whobig;
    }
  }

  for(int i = 1; i <= starti; i *= 2){
    for(int j = i; j < i*2; j++){
      long long comp = segtree[j];
      long long left = segtree[j*2];
      long long right = segtree[j*2+1];

      left = comp - left; right = comp - right;
      segtree[j*2] -= oritree[j*2]; segtree[j*2+1] -= oritree[j*2+1];
      oritree[j*2] += left; oritree[j*2+1] += right;
    }
  }

  long long result = 0;
  for(int i = 2; i < howmany+2; i++)
    result += oritree[i];

  printf("%lld\n", result);
  return 0;
}
