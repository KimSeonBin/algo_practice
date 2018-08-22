#include <stdio.h>

long long gcd(long long a, long long b){
  long long temp = 0;
  while(b != 0){
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
int main(){
  printf("n e\n");
  printf("- -----------\n");

  double e = 0;
  long long ae = 5, be = 2, de = 2;
  printf("0 1\n");
  printf("1 2\n");
  printf("2 2.5\n");
  for(int i = 3; i < 10; i++){
    long long ce = 1;
    de *= i;
    long long tempa = ae*de + be*ce, tempb = be*de, gcdab = gcd(tempa, tempb);
    ae = tempa / gcdab; be = tempb / gcdab;
    e = (double)ae / be;

    printf("%d %.9lf\n", i, e);
  }

  return 0;
}
