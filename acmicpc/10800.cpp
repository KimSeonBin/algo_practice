#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


/*
1. 각 크기별로 얼만큼 공을 잡아먹을 수 있는지 계산(scount)
//총합 계산

2. 공 번호별로 vector를 만들어 크기를 기준으로 오름차순 정렬.
각 공마다 자신보다 작은 공들의 합을 구한다.(ball2.presum)
//같은 공 중 자기보다 작은 공 총합 계산

3. low bound search로 ball2를 담고있는 vector에서 index를 찾는다.
scount와 ball2.presum의 차이가 답.
low bound로 찾기에 같은 공에서 같은 크기가 나와도 presum에 같은 크기가 사전에 더해지지 않는다.
*/
typedef struct ball{
  int c, s;
};

typedef struct ball2{
  int i, s, presum;

  bool operator< (ball2 a){
    if(s == a.s)
      return i < a.i;
    return s < a.s;
  }
};

vector<ball> v;
vector<ball2> v2[200001];
int scount[2002] = {0};

int lowbound(int s, int e, int index, int target){
  int mid = 0;
  while(s < e){
    mid = (s+e) / 2;
    if(v2[index][mid].s < target)
      s = mid + 1;
    else
      e = mid;
  }

  return v2[index][e].presum;
}

int main(){
  int n = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    ball temp;
    scanf("%d %d", &temp.c, &temp.s);
    v.push_back(temp);
    scount[temp.s + 1] += temp.s;

    ball2 temp2;
    temp2.i = i; temp2.s = temp.s; temp2.presum = 0;
    v2[temp.c].push_back(temp2);
  }

  for(int i = 1; i <= n; i++){
    if(!v2[i].size())
      continue;
    sort(v2[i].begin(), v2[i].end());
    for(int j = 0; j < v2[i].size()-1; j++){
      v2[i][j+1].presum += v2[i][j].presum + v2[i][j].s;
    }
  }

  for(int i = 1; i < 2001; i++){
    scount[i] += scount[i-1];
  }

  for(int i = 0; i < n; i++){
    printf("%d\n", scount[v[i].s] - lowbound(0, v2[v[i].c].size(), v[i].c, v[i].s));
  }

  return 0;
}
