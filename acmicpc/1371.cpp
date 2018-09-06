#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[27];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int ch = 0;
  while(cin.eof() == false){
    ch = cin.get();
    if(97 <= ch && ch <= 122)
      arr[ch-97]++;
  }

  vector<char> answer; int maxv = 0;
  for(int i = 0; i < 27; i++){
    if(maxv < arr[i]){
      maxv = arr[i];
      answer.clear();
      answer.push_back(i+97);
    }
    else if(maxv == arr[i]){
      answer.push_back(i+97);
    }
  }

  for(int i = 0; i < answer.size(); i++)
    cout << answer[i];
  return 0;
}
