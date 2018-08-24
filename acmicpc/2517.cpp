/*
runner 구조체를 통해 각 선수의 실력과 순서를 담는다.
이를 실력을 기준으로 잡고 오름차순으로 정렬한다.

segment tree는 순서를 의미에 둔다.

ex)
2
8
10
7
1
9
4
15

->
v   i
1   4
2   0
4   6
7   3
8   1
10  2
15  7

v[0] (5~7) -1
v[1] (1~7) -1
v[2] (7~7) -1
...

이를 통해 앞에 몇명의 선수가 있는지 알 수 있고 자신의 순서에서 segment tree에서 구한
값을 빼면 답이 나온다.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct runner{
  int val;//실력
  int index;//순서

  bool operator< (runner a){
    return val < a.val;
  }
};

vector<runner> v;
int segtree[2000001];
int grade[500001];

int startindex(int n){
  int in = 1;
  while(in < n){
    in *= 2;
  }
  return in;
}

int howmanyPass(int index){
  int result = 0;
  while(index > 0){
    result += segtree[index];
    index /= 2;
  }
  return result;
}

void setpass(int s, int e){
  while(s <= e){
    if(s % 2 == 1){
      segtree[s]++;
      s++;
    }
    if(e % 2 == 0){
      segtree[e]++;
      e--;
    }
    s /= 2;
    e /= 2;
  }
}

int main(){
  int n = 0, sindex = 0;
  scanf("%d", &n);

  sindex = startindex(n);
  for(int i = 0; i < n; i++){
    int t = 0;
    scanf("%d", &t);
    runner temp;
    temp.val = t; temp.index = i;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    int minuss = howmanyPass(sindex + v[i].index);
    grade[v[i].index] = v[i].index - minuss;
    setpass(sindex+v[i].index+1, sindex+n-1);
  }

  for(int i = 0; i < n; i++){
    printf("%d\n", grade[i]+1);
  }

  return 0;
}
