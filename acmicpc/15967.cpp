#include <stdio.h>
#include <vector>
using namespace std;
typedef struct diff{
  int s;
  int e;
  long long val;
};
vector<diff> dif;

long long sumtree[4000001];

int maxv(int a, int b){
  if(a > b)
    return a;
  return b;
}

int minv(int a, int b){
  if(a > b)
    return b;
  return a;
}

int startindex(int n){
  int result = 1;
  while(true){
    if(n >= result)
      result *= 2;
    else
      break;
  }
  return result;
}

//2번 쿼리는 반영하지 않고 저장 후 1번 쿼리 때 범위 비교를 통해 차이를 알아낸다.
void savechange(int s, int e, long long L){
  diff temp;
  temp.s = s; temp.e = e; temp.val = L;
  dif.push_back(temp);
}

long long getdiff(int s, int e){
  long long result = 0;
  for(int i = 0; i < dif.size(); i++){
    if(dif[i].e < s || dif[i].s > e)
      continue;
    int diffs = 0, diffe = 0;

    diffs = maxv(dif[i].s, s);
    diffe = minv(dif[i].e, e);
    long long temp = diffe - diffs + 1;
    result += temp * dif[i].val;
  }

  return result;
}

//segment tree 구간 합 구하기
long long getSum(int sindex, int s, int e){
  long long result = 0, gdiff = getdiff(s, e);
  s += sindex-1; e += sindex-1;

  while(s <= e){
    if(s % 2 == 0){
    }
    else{
      result += sumtree[s];
      s++;
    }

    if(e % 2 == 0){
      result += sumtree[e];
      e--;
    }
    else{
    }
    s /= 2;
    e /= 2;
  }
  return result + gdiff;
}

int main(){
  int n = 0, q1 = 0, q2 = 0, q = 0;
  scanf("%d %d %d", &n, &q1, &q2);

  int sindex = startindex(n);
  for(int i = 0; i < n; i++){
    scanf("%lld", &sumtree[sindex+i]);
  }

  //sumTree 구성
  for(int i = sindex; i > 1; i /= 2){
    for(int j = i; j < 2*i; j++){
      sumtree[j/2] += sumtree[j];
    }
  }

  q = q1 + q2;
  for(int i = 0; i < q; i++){
    int q = 0;
    scanf("%d", &q);
    if(q == 1){
      int s = 0, e = 0;
      scanf("%d %d", &s, &e);
      printf("%lld\n", getSum(sindex, s, e));
    }
    else{
      int s = 0, e = 0; long long L = 0;
      scanf("%d %d %lld", &s, &e, &L);
      if(s > e){
        int temp = s;
        s = e;
        e = s;
      }
      savechange(s, e, L);
    }
  }

  return 0;
}
