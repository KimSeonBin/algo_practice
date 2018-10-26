#include <cstdio>
#define MAXV 10000000000L

int main(){
  long long x = 0, y = 0, z = 0;
  scanf("%lld %lld", &x, &y);

  z = (y * 100) / x;

  long long s = 1, e = MAXV;

  while (s < e){
    long long m = (s+e) / 2;
    long long bsz = ((y + m) * 100) / (x + m);

    if(bsz <= z)
      s = m + 1;
    else
      e = m;
    // printf("%lld %lld %lld\n",s,e,bsz);
  }

  if(s == MAXV)
    s = -1;
  printf("%lld\n", s);

  return 0;
}
