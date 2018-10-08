#include <cstdio>
using namespace std;

int arr[510][510] = {0};

int maxv(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main(){
  int n = 0, m = 0, answer = 0;
  scanf("%d %d", &n, &m);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      //1. ....
      answer = maxv(answer, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3]);

      /*
      2.
      .
      .
      .
      .
      */
      answer = maxv(answer, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j]);


      int temp = 0;
      for(int k = i; k < i+2; k++)
        for(int q = j; q < j+3; q++)
          temp += arr[k][q];

      /*
      3.
      ...
       .
      */
      answer = maxv(answer, temp - arr[i+1][j] - arr[i+1][j+2]);

      /*
      4.
       .
      ...
      */
      answer = maxv(answer, temp - arr[i][j] - arr[i][j+2]);

      /*
      5.
       ..
      ..
      */
      answer = maxv(answer, temp - arr[i][j] - arr[i+1][j+2]);

      /*
      6.
      ..
       ..
      */
      answer = maxv(answer, temp - arr[i][j+2] - arr[i+1][j]);

      /*
      7.
      ...
      .
      */
      answer = maxv(answer, temp - arr[i+1][j+1] - arr[i+1][j+2]);

      /*
      8.
        .
      ...
      */
      answer = maxv(answer, temp - arr[i][j] - arr[i][j+1]);

      /*
      9.
      .
      ...
      */
      answer = maxv(answer, temp - arr[i][j+1] - arr[i][j+2]);

      /*
      10.
      ...
        .
      */
      answer = maxv(answer, temp - arr[i+1][j] - arr[i+1][j+1]);

      temp = 0;
      for(int k = i; k < i+3; k++)
        for(int q = j; q < j+2; q++)
          temp += arr[k][q];
      /*
      11.
      .
      ..
      .
      */
      answer = maxv(answer, temp - arr[i][j+1] - arr[i+2][j+1]);

      /*
      12.
       .
      ..
       .
      */
      answer = maxv(answer, temp - arr[i][j] - arr[i+2][j]);

      /*
      13.
      .
      ..
       .
      */
      answer = maxv(answer, temp - arr[i][j+1] - arr[i+2][j]);

      /*
      14.
       .
      ..
      .
      */
      answer = maxv(answer, temp - arr[i][j] - arr[i+2][j+1]);

      /*
      15.
      .
      .
      ..
      */
      answer = maxv(answer, temp - arr[i][j+1] - arr[i+1][j+1]);

      /*
      16.
       .
       .
      ..
      */
      answer = maxv(answer, temp - arr[i][j] - arr[i+1][j]);

      /*
      17.
      ..
      .
      .
      */
      answer = maxv(answer, temp - arr[i+1][j+1] - arr[i+2][j+1]);

      /*
      18.
      ..
       .
       .
      */
      answer = maxv(answer, temp - arr[i+1][j] - arr[i+2][j]);

      /*
      19.
      ..
      ..
      */
      answer = maxv(answer, arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1]);
    }
  }

  printf("%d\n", answer);
  return 0;
}
