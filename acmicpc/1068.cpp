#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int n = 0, root = 0, temp = 0;
  vector<vector<int>> tree;
  int del = 0;
  int answer = 0;

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    vector<int> treenode;
    tree.push_back(treenode);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    if(temp == -1){
      root = i;
    }
    else{
      tree[temp].push_back(i);
    }
  }
  scanf("%d", &del);

  queue<int> bfs;
  bfs.push(root);
  while(!bfs.empty()){
    int node = bfs.front();
    int treesize = tree[node].size();
    bfs.pop();

    if(node == del){
      continue;
    }
    for(int i = 0; i < tree[node].size(); i++){
      if(tree[node][i] == del){
        treesize--;
      }
    }

    if(treesize == 0){
      answer++;
      continue;
    }

    for(int i = 0; i < tree[node].size(); i++){
      bfs.push(tree[node][i]);
    }
  }
  printf("%d\n", answer);
  return 0;
}
