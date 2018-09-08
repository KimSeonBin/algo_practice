#include <stdio.h>
//2018.09.08
int divide(int width, int height, int target){
  /*
  나누는 최대 회수 : 2번
  1. 0번: width * height = target인 경우(target이 입력값의 면적과 같은 경우)
  2. 1번: width나 height가 target의 공약수인 경우
  3. 2번: target = a * b -> a, b가 width, height 범위 안에 드는 경우
  4. -1번:  target = a * b -> a, b가 width, height 범위를 초과하는 경우
  */
  int answer = 3;
  for(int i = 1; i <= 31676; i++){
    int temp1 = i;
    int temp2 = target / i;
    if(target % i != 0)
      continue;
    if((temp1 < width && temp2 < height) || (temp1 < height && temp2 < width)){
        if(answer > 2)
          answer = 2;
    }
    if((temp1 == width && temp2 == height) || (temp1 == height && temp2 == width)){
        answer = 0;
        break;
    }
    if( (temp1 == width && temp2 < height) ||
        (temp1 == height && temp2 < width) ||
        (temp2 == width && temp1 < height) ||
        (temp2 == height && temp1 < width)){
        if(answer > 1)
          answer = 1;
    }
  }
  return answer;
}

int main(){
  printf("%d\n", divide(5, 4, 12));
  return 0;
}
