#include <stdio.h>

long long backtrack(long long num, long long n, bool check[10]){
  long long temp = n - num, result = 0;
  bool istrue = true;

  bool ctemp[10] = {false};
  for(int i = 0; i < 10; i++)
    ctemp[i] = check[i];

  //check를 확인해 겹치는 숫자가 있는지 확인
  while(temp > 0){
    if(ctemp[temp % 10]){
      istrue = false;
      break;
    }
    ctemp[temp % 10] = true;
    temp /= 10;
  }

  //n-num이 0이 되는 것을 방지
  if(istrue && n - num > 0)
    return num;

  temp = num * 10;

  for(int i = 0; i < 10; i++){
    if(check[i])
      continue;
    check[i] = true;
    if(temp + (long long)i > n){
      check[i] = false;
      continue;
    }

    result = backtrack(temp + (long long )i, n, check);

    if(result > 0)
      return result;

    check[i] = false;
  }
  return 0;
}


int main(){
  long long n = 0, a = 0;
  scanf("%lld", &n);

  //0으로 시작할 수 없으니 1~9 같은 자연수로 재귀함수 시작
  for(int i = 1; i <= 9; i++){
    bool check[10] = {false};
    check[i] = true;
    a = backtrack(i, n, check);
    if(a > 0)
      break;
  }

  if(a == 0){
    printf("-1\n");
  }
  else
    printf("%lld + %lld\n", a, n-a);
  return 0;
}
