#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct voice{
  int index, va;
  bool operator< (voice a){
    if(va == a.va)
      return index < a.index;
    return va < a.va;
  }
};
vector<voice> v;

int main(){
  int n = 0, a = 0, d = 0;
  scanf("%d %d %d", &n, &a, &d);

  for(int i = 0; i < n; i++){
    voice temp;
    temp.index = i;
    scanf("%d", &temp.va);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  int preindex = -1, answer = 0;
  for(int i = 0; i < n; i++){
    if(v[i].index > preindex & v[i].va == a){
      answer++;
      preindex = v[i].index;
      a += d;
    }
  }
  
  printf("%d\n", answer);
  return 0;
}
