#include <iostream>
#include <string>

using namespace std;

/*
before == -1 -> 처음
          0 -> 100
          1 -> 0+
          2 -> 1+
          3 -> 01

0 -> (1 or 2) -> (3 or 0)
1 -> 1 -> ... -> 2
2 -> 2 -> ... -> (3 or 0)
3 -> (0 or 3)

*/

bool check100(string str, int n){
  if(n+2 >= str.size())
    return false;
  if(str.at(n) == '1' && str.at(n+1) == '0' && str.at(n+2) == '0')
    return true;
  else
    return false;
}

bool checkplus(string str, int n, char number){
  if(str.at(n) == number)
    return true;
  else
    return false;
}

bool check01(string str, int n){
  if(n+1 >= str.size())
    return false;
  if(str.at(n) == '0' && str.at(n+1) == '1')
    return true;
  else
    return false;
}

bool checkcontact(string str, int n, int before){
  if(n >= str.size())
    if(before >= 2)
      return true;
    else
      return false;

  if(before == -1 || before == 3){
    if(check100(str, n))
      if(checkcontact(str, n+3, 0))
        return true;
    if(check01(str, n))
      if(checkcontact(str, n+2, 3))
        return true;
  }
  else if(before == 0){
    if(checkplus(str, n, '0'))
      if(checkcontact(str, n+1, 1))
        return true;
    if(checkplus(str, n, '1'))
      if(checkcontact(str, n+1, 2))
        return true;
  }
  else if(before == 1){
    if(checkplus(str, n, '0')){
      if(checkcontact(str, n+1, 1))
        return true;
      }
    else{
      if(checkcontact(str, n+1, 2))
        return true;
    }
  }
  else if(before == 2){
    if(checkplus(str, n, '1'))
      if(checkcontact(str, n+1, 2))
        return true;

    if(check100(str, n))
      if(checkcontact(str, n+3, 0))
        return true;
    if(check01(str, n))
      if(checkcontact(str, n+2, 3))
        return true;
  }

  return false;
}

int main(){
  int n = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;

    if(checkcontact(str, 0, -1))
      cout << "YES" << "\n";
    else
      cout << "NO" << "\n";
  }
  return 0;
}
