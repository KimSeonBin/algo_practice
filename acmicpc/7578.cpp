/*
ex)
0   1   2   3   4
132 392 311 351 231
392 351 132 311 231
이를 같은 식별번호로 묶어 index로 표현한다면
132: (0,2)
231: (4,4)
311: (2,3)
351: (3,1)
392: (1,0)
이다.
(x,y)라 할 때
이를 x를 기준으로 오름차순 sort하면
(0,2), (1,0), (2,3), (3,1), (4,4)가 된다.
여기서 선분이 몇개가 교차하는지 알 수 있는 식은
y - (자신보다 앞에 있는 값들 중 자기보다 작은 y 갯수)이다.

why?
1) (0,2)와 겹치기 위해서는 누군가 0, 1이여야 한다.
따라서 2개. 그리고 2은 선택되었으니 3~4에 3이 선택됐다는 의미로 3~4구간에 -1
2) (1,0)은 0보다 작은 값은 없으니 0
1~4에 0이 선택됐다는 의미로 1~4에 -1
3) (2,3)은 0,1,2 가 될 수 있으나 0, 2는 선택되었으니 1개
3이 선택되었다는 의미로 4~4에 -1
4) (3,1)은 0이 될 수 있으나 이미 선택되었으니 0개
2~4구간에 -1
5) (4,4)은 0,1,2,3이 선택될 수 있으나 모두 선택되었으니 0개

따라서 2+0+1+0+0 = 3개

결과가 long long인 이유는 겹치는 선분의 갯수가 25만*25만이 될 수도 있는 경우의 수가
있기 때문이다.
ex) n=50만
1 ~ 25만 선분이 25만1 ~ 50만번 선분 각각 모두 겹친다고 하면 그렇다.
*/

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct machine{
  int id;
  int index;
  bool operator< (machine a){
    return id < a.id;
  }
};

typedef struct node{
  int a;
  int b;
  bool operator< (node na){
    return a < na.a;
  }
};

vector<machine> Aarr;
vector<machine> Barr;
vector<node> v;
long long segtree[2000001];

int getStartIndex(int index){
  int result = 1;
  while(result < index){
    result *= 2;
  }
  return result;
}

long long getMinus(int index){
  long long result = 0;
  while(index >= 1){
    result += segtree[index];
    index /= 2;
  }
  return result;
}

void setsegtree(int s, int e){
  while(s <= e){
    if(s % 2 == 1){
      segtree[s++]++;
    }
    if(e % 2 == 0){
      segtree[e--]++;
    }
    s /= 2; e /= 2;
  }
}

int main(){
  int n = 0, temp = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    machine mtemp;
    mtemp.id = temp; mtemp.index = i;
    Aarr.push_back(mtemp);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    machine mtemp;
    mtemp.id = temp; mtemp.index = i;
    Barr.push_back(mtemp);
  }

  sort(Aarr.begin(), Aarr.end());
  sort(Barr.begin(), Barr.end());

  for(int i = 0; i < n; i++){
    node ntemp;
    ntemp.a = Aarr[i].index; ntemp.b = Barr[i].index;
    v.push_back(ntemp);
  }
  sort(v.begin(), v.end());

  int sindex = getStartIndex(n);
  long long answer = 0;
  for(int i = 0; i < n; i++){
    answer += (v[i].b) - getMinus(sindex + v[i].b);
    setsegtree(sindex + v[i].b+1, sindex + n);
  }

  printf("%lld\n", answer);
  return 0;
}
