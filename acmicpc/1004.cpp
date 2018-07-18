#include <stdio.h>
#include <vector>
using namespace std;

typedef struct circle{
  int x;
  int y;
  int r;
};

int main(){
  int t = 0;
  scanf("%d", &t);

  int temp = 0;
  int temp1 = 0, temp2 = 0, temp3 = 0;
  for(int iter = 0; iter < t; iter++){
    int start[2] = {0}, dest[2] = {0};
    scanf("%d %d %d %d", &start[0], &start[1], &dest[0], &dest[1]);
    int check[1001] = {0};
    vector<circle> dot;
    scanf("%d", &temp);
    for(int i = 0; i < temp; i++){
      scanf("%d %d %d", &temp1, &temp2, &temp3);
      circle ttt;
      ttt.x = temp1; ttt.y = temp2; ttt.r = temp3*temp3;
      dot.push_back(ttt);
    }

    int answer = 0;
    int distance = 0;
    for(int i = 0; i < dot.size(); i++){
      //start와 비교
      distance = (dot[i].x-start[0])*(dot[i].x-start[0]) + (dot[i].y-start[1])*(dot[i].y-start[1]);
      if(distance < dot[i].r){
        check[i]++;
      }

      //dest와 비교
      distance = (dot[i].x-dest[0])*(dot[i].x-dest[0]) + (dot[i].y-dest[1])*(dot[i].y-dest[1]);
      if(distance < dot[i].r){
        check[i]++;
      }
    }

    for(int i = 0; i < temp; i++){
      if(check[i] == 1){
        answer++;
      }
    }


    printf("%d\n", answer);
  }

  return 0;
}
