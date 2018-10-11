#include <cstdio>

using namespace std;

int main(){
  int m = 0, n = 0;
  scanf("%d %d", &m, &n);

  if(m <= n){
    printf("%d\n", (m-1) + (m-1));
  }
  else{
    printf("%d\n", n + n - 1);
  }
  return 0;
}
