#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

/*
사대를 vector에 저장 -> sort

이후 동물의 (x, y)를 받고
1. y > L 일 때
  x가 사대와 일치해도 못 잡는다.
  pass

2. y <= L
  x를 기준으로 사대 v를 ㅣlow bound binary search
  나온 index와 왼쪽 element을 가지고 사대와 사냥감의 거리를 계산한다.
  그 중 작은 값과 L과 비교해 L 안에 들어오면 잡을 수 있는 사냥감
*/
vector<int> v;

int min(int a, int b){
  if(a > b)
    return b;
  return a;
}

int main(){
  int m = 0, n = 0, L = 0, temp = 0;
  int answer = 0;
  scanf("%d %d %d", &m, &n, &L);

  for(int i = 0; i < m; i++){
    scanf("%d", &temp);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    int x = 0, y = 0;
    scanf("%d %d", &x, &y);
    if(y > L)
      continue;

    int los = 0, loe = m, mid = 0;

    while(los < loe){//low bound binary search
      mid = (los+loe) / 2;
      if(x > v[mid]){
        los = mid+1;
      }
      else{
        loe = mid;
      }
    }

    int left = 0, right = 0;
    //left -> low bound 결과 index의 왼쪽, right -> low bound 결과 index
    if(los-1 < 0)
      left = abs(x-v[0]);
    else if(los-1 >= m)
      left = abs(x-v[m-1]);
    else
      left = abs(x-v[los-1]);

    if(los < 0)
      right = abs(x-v[0]);
    else if(los >= m)
      right = abs(x-v[m-1]);
    else
      right = abs(x-v[los]);

    if(L >= y + min(left, right))
      answer++;
  }

  printf("%d\n", answer);
  return 0;
}
