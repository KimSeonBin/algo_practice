#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int angle[361] = {0};
vector<int> v; // 이미 알고있는 각도들
deque<int> v2; // 더하거나 빼서 새로 생긴 각도

int abs(int a){
  if(a < 0)
    return -a;
  return a;
}

int main(){
  int n = 0, k = 0, vsize = 0, v2size = 0;
  scanf("%d %d", &n, &k);

  for(int i = 0; i < n; i++){
    int temp = 0;
    scanf("%d", &temp);
    v.push_back(temp);
    v2.push_back(temp);
    angle[temp]++;
  }

  while(v2.size() > 0){
    vsize = v.size();
    v2size = v2.size();
    for(int i = 0; i < v2size; i++){
      int temp = v2[0];
      v2.pop_front();
      for(int j = 0; j < vsize; j++){
        int pv = (temp + v[j]) % 360, absv = abs(temp - v[j]);
        angle[pv]++;
        if(angle[pv] == 1){// 새로 발견한 각도
          v.push_back(pv);
          v2.push_back(pv);
        }

        angle[absv]++;
        if(angle[absv] == 1){
          v.push_back(absv);
          v2.push_back(absv);
        }

      }
    }
  }

  for(int i = 0; i < k; i++){
    int s = 0;
    scanf("%d", &s);

    if(angle[s] == 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
