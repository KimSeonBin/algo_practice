#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct ver{
  int x, y, value;

  bool operator< (ver a){
    return value < a.value;
  }
};

vector<ver> vv;

int parent[10001] = {0};

int find(int a){
  while(parent[a] != a){
    a = parent[a];
  }
  return a;
}

bool join(int a, int b){
  int pa = find(a), pb = find(b);
  if(pa == pb)
    return false;

  parent[pa] = pb;
  return true;
}

int main(){
  int v = 0, e = 0;
  int answer = 0, mstsize = 0;
  scanf("%d %d", &v, &e);

  for(int i = 0; i <= v; i++)
    parent[i] = i;

  for(int i = 0; i < e; i++){
    ver temp;
    scanf("%d %d %d", &temp.x, &temp.y, &temp.value);
    vv.push_back(temp);
  }
  sort(vv.begin(), vv.end());

  for(int i = 0; i < e; i++){
    if(mstsize == v-1){
      break;
    }

    if(join(vv[i].x, vv[i].y)){
      answer += vv[i].value;
      mstsize++;
    }
  }

  printf("%d\n", answer);
  return 0;
}
