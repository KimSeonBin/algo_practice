#include <cstdio>
#include <vector>

using namespace std;

vector<int> v[400001];

int getStartindex(int n){
  int result = 1;
  while(result < n)
    result *= 2;
  return result;
}

void mergeSegment(int a, int b, int index){
  int i = 0, j = 0;
  for(; i < v[a].size(); i++){
    for(; j < v[b].size(); j++){
      if(v[a][i] >= v[b][j])
        v[index].push_back(v[b][j]);
      else
        break;
    }
    v[index].push_back(v[a][i]);
  }

  for(; j < v[b].size(); j++)
    v[index].push_back(v[b][j]);
}

void setSegmentTree(int sindex){
  for(int i = sindex; i > 1; i /= 2){
    for(int j = 0; j < i; j += 2){
      if(v[i+j].empty())
        continue;
      mergeSegment(i+j, i+j+1, (i+j)/2);
    }
  }
}

int getCount(int index, int target){
  int s = 0, e = v[index].size();
  while(s < e){
    int m = (s+e) / 2;
    if(v[index][m] > target)
      e = m;
    else
      s = m+1;
  }

  return s;
}

int querySegmentTree(int a, int b, int k){
  vector<int> point;

  while(a <= b){
    if(a % 2 == 1){
      point.push_back(a);
    }
    if(b % 2 == 0){
      point.push_back(b);
    }

    a = (a+1) / 2;
    b = (b-1) / 2;
  }

  int s = -1000000000, e = 1000000000;
  while(s < e){
    int m = (s + e) / 2, count = 0;
    if(s+e < 0)
      m = (s+e-1)/2;
    for(int i = 0; i < point.size(); i++){
      count += getCount(point[i], m);
    }

    if(count < k)
      s = m + 1;
    else
      e = m;
  }
  return s;
}

int main(){
  int n = 0, q = 0, sindex = 0;
  scanf("%d %d", &n, &q);
  sindex = getStartindex(n);

  for(int i = 0; i < n; i++){
    int temp = 0;
    scanf("%d", &temp);
    v[sindex + i].push_back(temp);
  }

  setSegmentTree(sindex);

  for(int iter = 0; iter < q; iter++){
    int i = 0, j = 0, k = 0;
    scanf("%d %d %d", &i, &j, &k);
    printf("%d\n", querySegmentTree(sindex + i-1, sindex + j-1, k));
  }

  return 0;
}
