/*
피보나치 수열 문제

p[n+1] = sum(p[n], p[n-1], ... p[n-d+1])

t가 20억까지 있기에 O(n)으로는 시간이 안된다.
따라서 행렬식을 이용해 푼다.
행렬식은
(1 1 1 1 1 .... 1)
 1 0 0 0 0 .... 0
 0 1 0 0 0 .... 0
 0 0 1 0 0 .... 0
 ............ 1 0
행 수는 d만큼
*/
#include <stdio.h>
#define MODULER 31991

int matrix[52][52];
int answer[52];

int howmul[33];

void check_howmul(int n){
  for(int i = 32; n > 0; n /= 2, i--){
    if(n % 2 == 1)
      howmul[i] = 1;
  }
}

void cal_matrix(int d){
  for(int i = 32; i >= 0; i--){
    if(howmul[i] == 1){
      int temp[52] = {0};
      for(int j = 1; j <= d; j++)
        temp[j] = answer[j];

      for(int j = 1; j <= d; j++){
        answer[j] = 0;
        for(int k = 1; k <= d; k++){
          answer[j] += matrix[j][k] * temp[k];
          answer[j] = answer[j] % MODULER;
        }
      }
    }

    //howmul 제곱
    int tempm[52][52];
    for(int j = 1; j <= d; j++)
      for(int k = 1; k <= d; k++)
        tempm[j][k] = matrix[j][k];



    for(int j = 1; j <= d; j++){
      for(int k = 1; k <= d; k++){
        matrix[j][k] = 0;
        for(int q = 1; q <= d; q++){
          matrix[j][k] += tempm[j][q] * tempm[q][k];
          matrix[j][k] = matrix[j][k] % MODULER;
        }
      }
    }
  }
}

int main(){
  int d = 0, t = 0;
  scanf("%d %d", &d, &t);

  for(int i = 1; i <= 50; i++){
    matrix[1][i] = 1;
    matrix[i+1][i] = 1;
  }

  answer[1] = 1;//t = 1
  check_howmul(t);
  cal_matrix(d);
  printf("%d\n", answer[1]);


  return 0;
}
