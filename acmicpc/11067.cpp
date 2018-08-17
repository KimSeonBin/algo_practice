#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct point{
  int x;
  int y;
  bool operator< (point b){
    if(x == b.x){
      return y < b.y;
    }
    return x < b.x;
  }
};

vector<point> datas; vector<point> datastemp;
vector<point> cafe;

int main(){
  int t = 0; scanf("%d", &t);

  for(int iter = 0; iter < t; iter++){
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
      int x = 0, y = 0;
      scanf("%d %d", &x, &y);

      point temp; temp.x = x; temp.y = y;
      datas.push_back(temp);
    }
    sort(datas.begin(), datas.end());

    point start;
    start.x = -1; start.y = 0;
    cafe.push_back(start);

    for(int i = 0; i < n; i++){
      if(datas[i].x == start.x){
        datastemp.push_back(datas[i]);
      }
      else{
        int datastempsize = datastemp.size();
        int cafesize = cafe.size();

        if(datastempsize == 1){
          cafe.push_back(datastemp[0]);
          start.x = datas[i].x;
          start.y = datas[i].y;
        }
        else if(datastempsize == 0){//가장 첫번째 결과 처리
          start.x = datas[i].x;
          start.y = datas[i].y;
        }
        else{
          bool startfront = true;
          if(cafesize == 0){
            if(datastemp[0].y != 0)
              startfront = false;
          }
          else{
            if(cafe[cafesize-1].y != datastemp[0].y)
              startfront = false;
          }

          if(startfront){
            for(int i = 0; i < datastempsize; i++){
              cafe.push_back(datastemp[i]);
            }
          }
          else{
            for(int i = datastempsize-1; i >= 0; i--){
              cafe.push_back(datastemp[i]);
            }
          }
          start.x = datas[i].x;
          start.y = cafe[cafe.size() - 1].y;
        }

        datastemp.clear();
        datastemp.push_back(datas[i]);
      }
    }

    if(!datastemp.empty()){
      int datastempsize = datastemp.size();
      if(start.y == datastemp[0].y){
        for(int i = 0; i < datastempsize; i++){
          cafe.push_back(datastemp[i]);
        }
      }
      else if(start.y == datastemp[datastempsize-1].y){
        for(int i = datastempsize-1; i >= 0; i--){
          cafe.push_back(datastemp[i]);
        }
      }
    }

    int m = 0, index = 0;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
      scanf("%d", &index);
      printf("%d %d\n", cafe[index].x, cafe[index].y);
    }

    datas.clear();
    cafe.clear();
    datastemp.clear();
  }
  return 0;
}
