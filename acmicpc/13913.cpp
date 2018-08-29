#include <stdio.h>
#include <queue>
#include <vector>

#define BOUNDARY 100000
using namespace std;

int check[BOUNDARY+1];
queue<int> q;

int main(){
  int n = 0, k = 0, tsize = 0, last_ele = 0;
  scanf("%d %d", &n, &k);


  for(int i = 0; i <= BOUNDARY; i++)
    check[i] = -1;

  q.push(n);
  check[n] = n;

  while(!q.empty()){
    last_ele = q.front();
    q.pop();
    //1. +1
    if(last_ele+1 <= BOUNDARY && check[last_ele+1] == -1){
      check[last_ele+1] = last_ele;
      q.push(last_ele+1);
    }
    //2. -1
    if(last_ele-1 >= 0 && check[last_ele-1] == -1){
      check[last_ele-1] = last_ele;
      q.push(last_ele-1);
    }
    //3. * 2
    if(last_ele*2 <= BOUNDARY && check[last_ele*2] == -1){
      check[last_ele*2] = last_ele;
      q.push(last_ele*2);
    }
  }

  vector<int> answer;
  answer.push_back(k);
  while(check[k] != k){
    answer.push_back(check[k]);
    k = check[k];
  }

  printf("%d\n", answer.size()-1);
  for(int i = answer.size()-1; i >= 0; i--){
    printf("%d ", answer[i]);
  }
  return 0;
}
