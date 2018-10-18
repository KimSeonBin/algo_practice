#include <cstdio>

using namespace std;

int segtree[400001] = {0};

int getsindex(int n){
  int result = 1;
  while(result < n){
    result *= 2;
  }
  return result;
}

int main(){
  int n, k;
  while(scanf("%d %d", &n, &k) != EOF){
    int sindex = getsindex(n);

    for(int i = 0; i < 400001; i++)
      segtree[i] = 1;

    for(int i = 0; i < n; i++){
      scanf("%d", &segtree[sindex+i]);
      if(segtree[sindex+i] > 0)
        segtree[sindex+i] = 1;
      else if(segtree[sindex+i] < 0)
        segtree[sindex+i] = -1;
    }

    for(int i = sindex; i > 1; i /= 2){
      for(int j = i; j < i*2; j++){
        segtree[j/2] *= segtree[j];
      }
    }

    char meth;
    int q, v;
    for(int i = 0; i < k; i++){
      scanf(" %c %d %d", &meth, &q, &v);

      if(meth == 'C'){
        if(v > 0)
          v = 1;
        else if(v < 0)
          v = -1;

        if(segtree[sindex+q-1] == v)
          continue;

        segtree[sindex+q-1] = v;
        for(int i = sindex+q-1; i > 1; i /= 2){
          if(i % 2 == 0)
            segtree[i/2] = segtree[i] * segtree[i+1];
          else
            segtree[i/2] = segtree[i] * segtree[i-1];
        }
      }
      else{
        int s = sindex + q - 1, e = sindex + v - 1, result = 1;
        while(s <= e){
          if(s % 2 == 1)
            result *= segtree[s];
          if(e % 2 == 0)
            result *= segtree[e];
          s = (s+1) / 2;
          e = (e-1) / 2;
        }

        if(result == 0)
          printf("0");
        else if(result > 0)
          printf("+");
        else
          printf("-");
      }
    }

    printf("\n");
  }
  return 0;
}
