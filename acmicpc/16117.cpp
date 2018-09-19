#include <stdio.h>
/*
@
# 10 10 15 45 33
@
# 99 10 27 44 96
@
# 11 99 97 98 75
@
# 13 47 67 55 0
@

행과 #이 일치할 때 == 시작점이 정수인 곳
1. 위
2. 오른쪽
3. 아래

@인 곳 == 시작점이 정수가 아닌 곳
1. 위
2. 아래
//오른쪽은 더해지는 map[i][j]가 없기에 무의미

*/
int arr[3002][3002] = {0};
int dp[3002][3002] = {0};

int maxx(int a, int b, int c){
  if(a < b)
    a = b;
  if(a > c)
    return a;
  return c;
}

int main(){
  int n = 0, m = 0, n2 = 0;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  n2 = n * 2 + 1;
  for(int j = 1; j <= m; j++){
    for(int i = 1; i <= n2; i++){
      int temp = 0, temp2 = 0, temp3 = 0;
      //temp: 위->아래 temp2: 오른쪽, temp3: 야래->위

      if(i % 2 != 0){
        if(i-2 >= 0)
          temp = dp[i-2][j-1] + arr[i/2][j];

        if(j - 2 >= 0)
          temp2 = dp[i][j-2];

        temp3 = dp[i+2][j-1] + arr[(i+1)/2][j];

        dp[i][j] = maxx(temp, temp2, temp3);
      }
      else{
        if(i - 2 >= 0)
          temp = dp[i-2][j-1];

        if(j == 1)
          temp2 = dp[i][j-1];
        else
          temp2 = dp[i][j-2] + arr[i/2][j-1];//바로 왼쪽의 dp[][]를 참조하면 1초 정지하는 움직임이 생길 수 있다. 따라서 2칸 왼쪽의 dp[][]를 참조
        if(j == m) //마지막 열에서는 바로 왼쪽의 dp[][]를 참조 가능
          temp2 = maxx(temp2, dp[i][j-1], 0);

        temp3 = dp[i+2][j-1];

        dp[i][j] = arr[i/2][j] + maxx(temp, temp2, temp3);
      }
    }
  }

  int maxv = 0;
  for(int i = 1; i <= n2; i++){
    maxv = maxx(maxv, dp[i][m], 0);
  }

  printf("%d\n", maxv);
  return 0;
}
