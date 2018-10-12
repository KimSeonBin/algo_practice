#include <cstdio>

using namespace std;
/*
2a + 1
3a + 3
4a + 6
5a + 10
*/
int main(){
  int n = 0, L = 0, temp = 1;
  scanf("%d %d", &n, &L);
  for(int i = 2; i <= 100; i++){
    if(i < L){
      temp += i;
      continue;
    }

    if((n-temp) % (i) == 0 && (n-temp) >= 0){
      for(int j = 0; j < i; j++){
        printf("%d ", j + (n-temp) / i);
      }
      return 0;
    }

    temp += i;
  }

  printf("-1\n");
  return 0;
}
