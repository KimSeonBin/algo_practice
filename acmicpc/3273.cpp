#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
bool check[100001] = {false};

int search(int target){
  int s = 0, e = v.size()-1;
  while (s <= e) {
    int m = (s + e) / 2;
    if(v[m] == target){
      return m;
    }
    else if(v[m] < target){
      s = m + 1;
    }
    else{
      e = m - 1;
    }
  }
  return -1;
}

int main(){
  int n = 0, answer = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int temp = 0;
    scanf("%d", &temp);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  int target = 0;
  scanf("%d", &target);

  for(int i = 0; i < n; i++){
    if(check[i] | v[i] >= target)
      continue;

    int bsindex = search(target - v[i]);
    if(bsindex == -1 || bsindex == i)
      continue;

    check[i] = true;
    check[bsindex] = true;
    answer++;
  }

  printf("%d\n", answer);
  return 0;
}
