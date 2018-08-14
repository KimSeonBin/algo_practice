#include <stdio.h>
#include <cmath>
#define gob 1000
#define INF 10000000

int main(){
  int t = 0;
  scanf("%d", &t);
  for(int iter = 0; iter < t; iter++){
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int score[1001] = {0};
    int lost[1001] = {0};
    for(int i = 0; i < m; i++){
      int a = 0, b = 0, c = 0, d = 0;
      scanf("%d %d %d %d", &a, &b, &c, &d);
      score[a] += c; lost[a] += d;
      score[b] += d; lost[b] += c;
    }

    double pytha[1001] = {0};
    for(int i = 1; i <= n; i++){
      long long S2 = (long long) score[i] * score[i];
      long long A2 = (long long) lost[i] * lost[i];
      if(S2 == 0 && A2 == 0)
        pytha[i] = 0;
      else
        pytha[i] = ((double)S2 / (S2 + A2));
    }


    double maxvalue = 0, minvalue = INF;
    for(int i = 1; i <= n; i++){
      if(maxvalue < pytha[i])
        maxvalue = pytha[i];
      if(minvalue > pytha[i])
        minvalue = pytha[i];
    }
    printf("%.lf\n", floor(maxvalue * gob));
    printf("%.lf\n", floor(minvalue * gob));
  }

  return 0;
}
