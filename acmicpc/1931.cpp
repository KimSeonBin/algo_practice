#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct timee{
  int s, e;

  bool operator< (timee a){
    if(e == a.e){
      return s < a.s;
    }
    return e < a.e;
  }
};
vector<timee> v;

int main(){
  int n = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int s = 0, e = 0;
    scanf("%d %d", &s, &e);
    timee t;
    t.s = s; t.e = e;
    v.push_back(t);
  }
  sort(v.begin(), v.end());

  int e = v[0].e, count = 1;
  for(int i = 1; i < n; i++){
    if(e <= v[i].s){
      count++;
      e = v[i].e;
    }
  }

  printf("%d\n", count);

  return 0;
}
