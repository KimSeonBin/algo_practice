#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> papers;

int main(){
  int n = 0, answer = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int temp = 0;
    scanf("%d", &temp);
    papers.push_back(temp);
  }
  sort(papers.begin(), papers.end());

  for(int i = 0; i <= n; i++){
    int qi = n;
    for(int j = 0; j < n; j++){
      if(papers[j] < i)
        qi--;
      else
        break;
    }
    if(qi < i)
      break;
    answer = i;
  }
  printf("%d\n", answer);
  return 0;
}
