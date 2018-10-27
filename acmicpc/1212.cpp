#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convert8to2(string n){
  if(n == "0")
    return "0";

  string result;
  for(int i = 0; i < n.size(); i++){
    int ntemp = n.at(i) - '0', digits = 1;
    string temp;
    while(ntemp > 0){
      temp += to_string(ntemp % 2);
      ntemp /= 2;
    }
    if(i > 0){
      for(int j = temp.size(); j < 3; j++)
        temp += "0";
    }
    reverse(temp.begin(), temp.end());
    result += temp;
  }
  return result;
}

int main(){
  string n;
  cin >> n;
  string answer = convert8to2(n);
  cout << answer << "\n";
  return 0;
}
