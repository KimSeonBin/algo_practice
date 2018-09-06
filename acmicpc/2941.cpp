#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  map<string, int> ha;
  ha.insert({"c=", 1});
  ha.insert({"c-", 1});
  ha.insert({"dz=", 1});
  ha.insert({"d-", 1});
  ha.insert({"lj", 1});
  ha.insert({"nj", 1});
  ha.insert({"s=", 1});
  ha.insert({"z=", 1});


  string s;
  cin >> s;

  int answer = 0, ssize = s.size();
  for(int i = 0; i < ssize; ){
    if(i+2 <= ssize){
      string s2 = s.substr(i, 2);
      if(ha.find(s2) != ha.end()){
        answer++;
        i += 2;
        continue;
      }
    }
    if(i+3 <= ssize){
      string s3 = s.substr(i, 3);
      if(ha.find(s3) != ha.end()){
        answer++;
        i += 3;
        continue;
      }
    }
    answer++;
    i++;
  }

  cout << answer << '\n';
  return 0;
}
