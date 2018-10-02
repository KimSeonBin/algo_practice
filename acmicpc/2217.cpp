#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct rope{
  int str, index;
  bool operator< (rope a){
    if(str == a.str)
      return index < a.index;
    return str > a.str;
  }
};

vector<rope> v;

int main(){
  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    rope temp; temp.index = i;
    scanf("%d", &temp.str);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  int answer = v[0].str;
  for(int i = 1; i < n; i++){
    if(answer < v[i].str * (i+1)){
      answer = v[i].str * (i+1);
    }
  }

  printf("%d\n", answer);

  return 0;
}
