#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;

int main(){
  int t = 0; scanf("%d", &t);

  for(int iter = 0; iter < t; iter++){
    char str1[202], str2[202];
    scanf(" %s", str1); scanf(" %s", str2);

    deque<int> index0, index1, indexq0, indexq1;

    int strsize = strlen(str1), answer = 0;
    int str1_0 = 0, str1_1 = 0, str1_q = 0;
    int str2_0 = 0, str2_1 = 0;
    for(int i = 0; i < strsize; i++){
      if(str1[i] == '0')
        str1_0++;
      else if(str1[i] == '1')
        str1_1++;
      else
        str1_q++;

      if(str2[i] == '0')
        str2_0++;
      else if(str2[i] == '1')
        str2_1++;

      if(str1[i] == '0' && str2[i] == '1')
        index0.push_back(i);
      if(str1[i] == '1' && str2[i] == '0')
        index1.push_back(i);
      if(str1[i] == '?' && str2[i] == '0')
        indexq0.push_back(i);
      if(str1[i] == '?' && str2[i] == '1')
        indexq1.push_back(i);
    }

    while(!index0.empty() && !index1.empty()){//0, 1 swap
      index0.pop_front();
      index1.pop_front();
      answer++;
    }

    /*
    1. 0-1이 남았을 경우
      1-1. ?가 없는 경우
        0->1로 치환
      1-2. ?가 있는 경우
        ?을 0, 1로 치환
        0을 1로 치환

    2. 1->0이 남았을 경우
      2-1. ?가 있는 경우
        ?-1과 교환(?가 부족하면 fail)
        ?을 0, 1로 치환
      2-2. ?가 없는 경우
        fail

    3. 모두 swap 된 경우
      ?을 0, 1에 맞게 치환
    */

    if(index0.size() > 0){
      if(str1_q > 0){
        answer += str1_q;
        answer += index0.size();
      }
      else{
        answer += index0.size();
      }
    }
    else if(index1.size() > 0){
      if(str1_q > 0){
        if(indexq1.size() < index1.size())
          answer = -1;
        else{
          answer += index1.size();
          answer += str1_q;
        }
      }
      else{
        answer = -1;
      }
    }
    else{
      answer += str1_q;
    }

    printf("Case %d: %d\n", iter+1, answer);
  }
  return 0;
}
