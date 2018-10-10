#include <cstdio>
#include <stack>

using namespace std;

stack<int> s[7];

int main(){
  int n = 0, m = 0, answer = 0;
  scanf("%d %d", &n, &m);

  for(int i = 1; i <= 6; i++){
    s[i].push(0);
  }

  for(int i = 0; i < n; i++){
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);

    while(s[a].top() > b){
      s[a].pop();
      answer++;
    }

    if(s[a].top() != b){
      s[a].push(b);
      answer++;
    }
  }

  printf("%d\n", answer);
  return 0;
}
