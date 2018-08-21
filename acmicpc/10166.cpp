#include <stdio.h>

int seats[2001];//1부터 시작해 2000까지의 좌석이 가려짐으로 인한 각 단계별 좌석 수
int answer[2001];//seats에서 구한 값을 바탕으로 d1~d2의 좌석 수

int main(){
  int d1 = 0, d2 = 0, result = 1;//result에 1로 설정해 맨 첫번째는 고려하지 않을 수 있다
  scanf("%d %d", &d1, &d2);

  for(int i = 1; i <= 2000; i++){
    seats[i] = i-1;
    answer[i] = i-1;
  }

  for(int i = 2; i <= 2000; i++){
    /*
    가려지는 좌석을 빼는 단계 수행
    하지만 각 단계 별 d1~d2 구간에 처음 만나는 단계는 답에서 가려지지 않으므로 firstmeet을
    두어 차감하는 것을 방지한다
    */
    bool firstmeet = true;

    for(int j = 1; i*j <= 2000; j++){
      if(j == 1){
        if(d1 <= i && i <= d2){
          firstmeet = false;
        }
        continue;
      }
      seats[i*j] -= seats[i];
      answer[i*j] -= seats[i];
      if(d1 <= i*j && i*j <= d2){
        if(firstmeet){
          firstmeet = false;
          answer[i*j] += seats[i];
        }
      }
    }

  }
  for(int i = d1; i <= d2; i++){
    result += answer[i];
  }
  printf("%d\n", result);
  return 0;
}
