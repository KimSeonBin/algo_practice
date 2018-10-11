#include <iostream>
#include <stack>

using namespace std;

stack<char> s;
stack<char> answer;
int main(){
  string str, bomb;

  cin >> str;
  cin >> bomb;

  int bomblast = bomb.size() - 1;
  for(int i = 0; i < str.size(); i++){
    s.push(str.at(i));

    if(s.top() == bomb.at(bomblast) && s.size() > bomblast){
      // stack 맨 위와 bomb 마지막 글자를 비교해 같다면 폭탄 문자인지 확인
      stack<char> temp;
      for(int j = bomblast; j >= 0; j--){
        if(s.top() == bomb.at(j)){
          temp.push(s.top());
          s.pop();
        }
        else{
          break;
        }
      }

      if(temp.size() == bomb.size())// 맡다면 폭파
        continue;
      else{//아니라면 다시 stack에 push
        while(!temp.empty()){
          s.push(temp.top());
          temp.pop();
        }
      }
    }
  }

  while(!s.empty()){
    answer.push(s.top());
    s.pop();
  }

  if(answer.size() == 0)
    cout << "FRULA" << "\n";
  else
    while(!answer.empty()){
      cout << answer.top();
      answer.pop();
    }

  return 0;
}
