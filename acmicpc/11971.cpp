#include <stdio.h>

int speed[109] = {0};

int maxx(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main(){
  int n = 0, m = 0, maxv = 0;
  scanf("%d %d", &n, &m);

  int temp = 0;
  for(int i = 0; i < n; i++){
    int x = 0, s = 0;
    scanf("%d %d", &x, &s);
    for(int j = temp+ 1 ; j <= temp + x; j++)
      speed[j] = s;

    temp += x;
  }

  temp = 0;
  for(int i = 0; i < m; i++){
    int x = 0, s = 0;
    scanf("%d %d", &x, &s);
    for(int j = temp + 1; j <= temp + x; j++){
      if(s <= speed[j])
        continue;
      maxv = maxx(maxv, s - speed[j]);
    }

    temp += x;
  }


  printf("%d\n", maxv);
  return 0;
}
