#include <cstdio>

using namespace std;

int segtree[400001] = {0};

int main(){
  int index = 1;
  int n = 0, m = 0;
  scanf("%d %d\n", &n, &m);

  while(index < n){
    index *= 2;
  }

  for(int i = 0; i < n; i++){
    scanf("%d", &segtree[index+i]);
  }

  for(int i = index; i > 1; i /= 2){
    for(int j = 0; j < i; j += 2){
      if(segtree[i+j] < segtree[i+j+1])
        segtree[(i+j) / 2] = segtree[i+j];
      else
        segtree[(i+j) / 2] = segtree[i+j+1];
    }
  }

  for(int i = 0; i < m; i++){
    int s = 0, e = 0, answer = 2100000000;
    scanf("%d %d", &s, &e);
    s = index + s - 1;
    e = index + e - 1;

    while(s <= e){
      if(s % 2 == 1){
        if(answer > segtree[s])
          answer = segtree[s];
      }
      if(e % 2 == 0){
        if(answer > segtree[e])
          answer = segtree[e];
      }
      s = (s+1) / 2;
      e = (e-1) / 2;
    }

    printf("%d\n", answer);
  }
}
