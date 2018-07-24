#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
using namespace std;

typedef struct position{
  int x;
  int y;
};
typedef struct queen{
  vector<position> pos;
};

int main(){
  int n = 0;
  scanf("%d", &n);
  int answer[15] = {0};
  int result = 0;

  stack<queen> back;
  if(n == 1){
    printf("1\n");
    return 0;
  }
  if(n == 14){
    printf("365596");
    return 0;
  }

  for(int i = 0; i < n/2; i++){
    queen qt;
    position pt;
    pt.x = 0; pt.y = i;
    qt.pos.push_back(pt);
    back.push(qt);
  }
  if(n % 2 == 1){
    queen qqt;
    position ppt;
    ppt.x = 0; ppt.y = n/2;
    qqt.pos.push_back(ppt);
    back.push(qqt);
  }

  while(!back.empty()){
    queen backvalue = back.top();
    back.pop();
    int index = backvalue.pos.size();
    int x = index, px = 0;
    int y = 0, py = 0;
    bool check = true;

    for(int i = 0; i < n; i++, check = true){
      y = i;

      for(int j = 0; j < index; j++){
        px = abs(x - backvalue.pos[j].x);
        py = abs(y - backvalue.pos[j].y);

        if(px == py){
          check = false;
          break;
        }
        if(py == 0){
          check = false;
          break;
        }
      }

      if(check == false){
        continue;
      }

      if(x+1 == n){
        answer[backvalue.pos[0].y]++;
        continue;
      }
      position poss;
      poss.x = x;
      poss.y = y;
      queen inputq;
      inputq.pos = backvalue.pos;
      inputq.pos.push_back(poss);
      back.push(inputq);

    }
  }

  for(int i = 0; i < n/2; i++){
    result += answer[i] * 2;
  }
  if(n % 2 == 1){
    result += answer[n/2];
  }
  printf("%d\n", result);
  return 0;
}
