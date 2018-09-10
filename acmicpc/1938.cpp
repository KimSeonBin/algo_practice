#include <stdio.h>
#include <queue>
using namespace std;

typedef struct tree{
  int x[3], y[3];
  int count;
};
queue<tree> q;


char map[52][52];
bool doublecheck[52][52][2];//중복체크 [][][0] -> 가로, [][][1] -> 세로
int result = 100000000;
int dirr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int minn(int a, int b){
  if(a < b)
    return a;
  return b;
}

int maxv(int a, int b){
  if(a > b)
    return a;
  return b;
}

int main(){
  int n = 0, tree_count = 0;
  tree t;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      scanf(" %c", &map[i][j]);

      if(map[i][j] == 'B'){
        t.x[tree_count] = i; t.y[tree_count] = j;
        tree_count++;
      }
    }
  }

  t.count = 0;
  q.push(t);

  while(!q.empty()){
    tree tre = q.front(); q.pop();

    //E 자리에 왔는지 확인
    int ecount = 0;
    for(int i = 0; i < 3; i++){
      if(map[tre.x[i]][tre.y[i]] == 'E'){
        ecount++;
      }
    }
    if(ecount == 3){
      result = minn(result, tre.count);
      break;
    }

    //1~4 U, D, L, R
    for(int i = 0; i < 4; i++){
      bool check2 = true;
      tree newtree;
      for(int j = 0; j < 3; j++){
        newtree.x[j] = tre.x[j] + dirr[i][0];
        newtree.y[j] = tre.y[j] + dirr[i][1];

        if(newtree.x[j] <= 0 || newtree.x[j] > n || newtree.y[j] <= 0 || newtree.y[j] > n){
          check2 = false;
          break;
        }
        if(map[newtree.x[j]][newtree.y[j]] == '1'){
          check2 = false;
          break;
        }
      }
      if(check2){
        if(newtree.x[0] == newtree.x[1]){
          if(doublecheck[newtree.x[1]][newtree.y[1]][0])
            continue;
          else
            doublecheck[newtree.x[1]][newtree.y[1]][0] = true;
        }
        if(newtree.y[0] == newtree.y[1]){
          if(doublecheck[newtree.x[1]][newtree.y[1]][1])
            continue;
          else
            doublecheck[newtree.x[1]][newtree.y[1]][1] = true;
        }

        newtree.count = tre.count + 1;
        q.push(newtree);
      }

    }

    //5. T
    bool check = true;
    if(tre.x[0] == tre.x[1]){
      /*
      (2, 2) (2, 3) (2, 4)
      ->
      (1, 2) ...
      (3, 2) ...에 '1'이 있는지 확인
      */
      for(int i = 0; i < 3; i++){
        if(map[tre.x[i]-1][tre.y[i]] == '1'){
          check = false;
          break;
        }
        if(map[tre.x[i]+1][tre.y[i]] == '1'){
          check = false;
          break;
        }
      }
    }
    else if(tre.y[0] == tre.y[1]){
      /*
      (2, 3) (3, 3) (4, 3)
      ->
      (2, 2) ...
      (2, 4) ...
      */
      for(int i = 0; i < 3; i++){
        if(map[tre.x[i]][tre.y[i]-1] == '1'){
          check = false;
          break;
        }
        if(map[tre.x[i]][tre.y[i]+1] == '1'){
          check = false;
          break;
        }
      }
    }

    if(!check)
      continue;
    if(tre.x[0] == tre.x[1]){//--- 로 눕혀있는 나무
      /*
      (2, 2) (2, 3) (2, 4)
      ->
      (1, 3) (2, 3) (3, 3)
      */
      tre.y[0] = tre.y[2] = tre.y[1];
      tre.x[0] = tre.x[1] - 1;
      tre.x[2] = tre.x[1] + 1;
    }
    else if(tre.y[0] == tre.y[1]){//1자로 세워져있는 나무
      /*
      (2, 3) (3, 3) (4, 3)
      ->
      (3, 2) (3, 3) (3, 4)
      */
      tre.x[0] = tre.x[2] = tre.x[1];
      tre.y[0] = tre.y[1] - 1;
      tre.y[2] = tre.y[1] + 1;
    }
    for(int j = 0; j < 3; j++){
      if(tre.x[j] <= 0 || tre.x[j] > n || tre.y[j] <= 0 || tre.y[j] > n || map[tre.x[j]][tre.y[j]] == '1'){
        check = false;
        break;
      }
    }
    if(!check)
      continue;

    if(tre.x[0] == tre.x[1]){
      if(doublecheck[tre.x[1]][tre.y[1]][0])
        continue;
      else
        doublecheck[tre.x[1]][tre.y[1]][0] = true;
    }
    if(tre.y[0] == tre.y[1]){
      if(doublecheck[tre.x[1]][tre.y[1]][1])
        continue;
      else
        doublecheck[tre.x[1]][tre.y[1]][1] = true;
    }
    tre.count++;
    q.push(tre);
  }


  if(result == 100000000)//불가능한 경우
    result = 0;
  printf("%d\n", result);
  return 0;
}
