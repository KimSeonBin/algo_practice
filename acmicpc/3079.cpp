#include<stdio.h>

long long gate[100001];

int main(){
  long long n = 0, m = 0;
  scanf("%lld %lld", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%lld", &gate[i]);
  }

  long long s = 0, e = 1000000000000000000, mid = 0;
  while(s <= e){
    mid = (s+e) / 2;
    long long result = 0;
    for(int i = 0; i < n; i++)
      result += mid / gate[i];

    if(m > result){
      s = mid+1;
    }
    else if(m <= result){
      e = mid-1;
    }
  }
  printf("%lld\n", s);
  return 0;
}
