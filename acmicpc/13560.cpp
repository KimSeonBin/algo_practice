#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> scores;
int checkarr[10001] = {0};

int ntotal(int n){
  return (n * (n-1)) / 2;
}

int main(){
  int n = 0;
  scanf("%d", &n);

  int totalcheck = 0;
  bool check = true;
  for(int i = 0; i < n; i++){
    int temp = 0;
    scanf("%d", &temp);
    scores.push_back(temp);
    totalcheck += temp;
  }

  if(totalcheck != ntotal(n)){
    check = false;
  }

  sort(scores.begin(), scores.end());

  for(int i = 1; i <= n; i++)
    checkarr[i] = i;

  for(int i = 0; i < n; i++){
    if(scores[i] == checkarr[i])
      continue;
    else if(scores[i] < checkarr[i]){
      check = false;
      break;
    }
    int temp = scores[i] - checkarr[i];
    checkarr[i+1] -= temp;
  }

  if(check)
    printf("1\n");
  else
    printf("-1\n");
  return 0;
}
