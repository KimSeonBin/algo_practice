#include <stdio.h>
//2018.09.08
int producing(int song, int length, int total){
  int answer = 0;
  int oneCD = (total+1) / (length+1);//하나의 CD에 들어갈 수 있는 최대 개수

  if(oneCD % 13 == 0)//한개의 CD에 13배수가 들어가면 1을 빼 음반에 13배수가 들어가는 것을 방지
    oneCD--;

  answer = song / oneCD;
  if(song % oneCD != 0)
      answer++;

  if((song % oneCD) % 13 == 0 && (song % oneCD) > 0){
    if((answer == 1) || (answer > 1 && (oneCD - 1) % 13 == 0))
      answer++;
    //ex)oneCD = 14, 마지막 CD 13개 곡이 있는 경우 한개의 CD를 더 만들어야 한다.
    //ex)CD가 한개밖에 없는데 13배수이면 CD를 한개 더 만든다.
  }
  return answer;
}

int main(){
  printf("%d\n", producing(7, 2, 6)); //4
  printf("%d\n", producing(20, 1, 100));//1
  printf("%d\n", producing(26, 1, 100));//2
  printf("%d\n", producing(63, 1, 100));//2
  printf("%d\n", producing(67, 271, 1000));//23
}
