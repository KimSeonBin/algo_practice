#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct interviewee{
  int paper;
  int meet;

  bool operator< (interviewee a){
    return paper < a.paper;
  }
};

vector<interviewee> v;

int main(){
  int t = 0;
  scanf("%d", &t);

  for(int iter = 0; iter < t; iter++){
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      int a = 0, b = 0;
      scanf("%d %d", &a, &b);
      interviewee temp;
      temp.paper = a; temp.meet = b;
      v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int answer = 1, comp = v[0].meet;
    for(int i = 1; i < n; i++){
      if(v[i].meet < comp){
        comp = v[i].meet;
        answer++;
      }
    }

    printf("%d\n", answer);
    v.clear();
  }
}
