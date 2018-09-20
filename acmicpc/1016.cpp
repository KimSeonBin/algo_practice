#include <stdio.h>

bool check[1000001] = {false};
bool primenono[1000001] = {false};

/*
1. 1 ~ 1000000 사이의 소수를 구한다.
2. 소수의 제곱을 구한다.
3. min~max 사이의 수 중 제곱수와 나누어 떨어지는 수를 체크한다.
4. 체크하지 않은 수가 answer
*/
int main(){
  long long min = 0, max = 0;
  scanf("%lld %lld", &min, &max);

  for(int i = 2; i <= 1000; i++){
    //1-1. 1~1000의 소수 구하기.
    if(check[i])
      continue;

    //2, 3. 소수의 제곱수 구하기. 소수 제곱수의 min~max에 들어가는 최소 배수를 구함
    long long p = (long long) i * i;
    long long st = min / p;
    if(min % p > 0)
      st++;

    if(p*st - min > 1000000)
      continue;

    //3. 소수 제곱수의 배수 체크
    for(long long j = p * st; j <= max; j += p){
      primenono[j-min] = true;
    }

    for(int j = i+i; j <= 1000000; j += i)
      check[j] = true;
  }

  for(int i = 1001; i < 1000000; i++){
    //1-2. 1001 ~ 1000000사이의 소수 구하기. 이하 동문
    if(check[i])
      continue;

    long long p = (long long) i * (long long)i;
    long long st = min / p;

    if(min % p > 0)
      st++;

    if(p*st - min > 1000000)
      continue;
    for(long long j = p * st; j <= max; j += p){
      primenono[j-min] = true;
    }
  }

  int answer = 0;
  for(int i = 0; i <= max-min; i++)
    if(!primenono[i])
      answer++;

  printf("%d\n", answer);

  return 0;
}
