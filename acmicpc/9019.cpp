#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct item{
  string meth;
  int num;
};

queue<item> q;

item methodD(item temp){
  int cal = temp.num;
  temp.num = (cal * 2) % 10000;
  temp.meth += "D";
  return temp;
}

item methodS(item temp){
  int cal = temp.num;
  if(temp.num == 0){
    temp.num = 9999;
  }
  else{
    temp.num = cal-1;
  }
  temp.meth += "S";
  return temp;
}
item methodL(item temp){
  int cal = temp.num / 1000;
  temp.num = (temp.num % 1000) * 10 + cal;
  temp.meth += "L";
  return temp;
}
item methodR(item temp){
  int cal = temp.num % 10;
  temp.num = cal * 1000 + (temp.num / 10);
  temp.meth += "R";
  return temp;
}

bool check(item temp, int b){
  if(temp.num == b){
    return true;
  }
  return false;
}

int main(){
  int t = 0;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  scanf("%d", &t);
  int a = 0, b = 0;

  for(int iter = 0; iter < t; iter++){
    bool checknum[10001] = {false};
    scanf("%d %d", &a, &b);
    item titem;
    titem.num = a;

    while(q.size() != 0){
      q.pop();
    }
    q.push(titem);

    while(q.size() != 0){
      item temp = q.front();
      q.pop();

      item result;
      result = methodD(temp);
      if(check(result, b)){
        cout << result.meth << '\n';
        break;
      }
      else{
        if(checknum[result.num] == false){
          q.push(result);
          checknum[result.num] = true;
        }
      }

      result = methodS(temp);
      if(check(result, b)){
        cout << result.meth << '\n';
        break;
      }
      else{
        if(checknum[result.num] == false){
          q.push(result);
          checknum[result.num] = true;
        }
      }

      result = methodL(temp);
      if(check(result, b)){
        cout << result.meth << '\n';
        break;
      }
      else{
        if(checknum[result.num] == false){
          q.push(result);
          checknum[result.num] = true;
        }
      }

      result = methodR(temp);
      if(check(result, b)){
        cout << result.meth << '\n';
        break;
      }
      else{
        if(checknum[result.num] == false){
          q.push(result);
          checknum[result.num] = true;
        }
      }
    }
  }
  return 0;
}
