#include <iostream>
#include <string>
using namespace std;

int main(){
  string sen;
  cin >> sen;

  int temp = -1, temp2 = 0, answer = 0;
  bool minus = false;
  //temp -> 숫자 판별, temp2 = 계속해서 더하기 or 빼기

  for(int i = 0; i < sen.size(); i++){
    char t = sen.at(i);
    if(t >= '0' && t <= '9'){
      if(temp == -1){
        temp = int(t)-48;
      }
      else{
        temp = temp * 10 + int(t)-48;
      }
    }

    if(t == '+'){
      temp2 += temp;
      temp = -1;
    }
    else if(t == '-'){
      if(minus){
        answer -= temp2;
        answer -= temp;
      }
      else{
        answer += temp2;
        answer += temp;
        minus = true;
      }

      temp2 = 0;
      temp = -1;
    }
  }
  temp2 += temp;


  if(minus){
    answer -= temp2;
  }
  else{
    answer += temp2;
  }

  cout << answer;
  return 0;
}
