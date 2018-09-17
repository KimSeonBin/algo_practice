#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

/*
오일러 회로 가능 여부 판별
->
각 정점마다 선분의 개수를 센 뒤 모든 정점의 선분이 짝수개여야 함.

https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220800097205&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F
Hierholzer's Algorithm
1. 아무 정점에서 시작
2. 갈 수 있는 선을 따라 출발점까지 움직인다. 움직인선은 중복체크.
3. 2번을 진행할 수 없을 때까지 반복
4. 만일 움직일 수 있는 정점이 더 존재한다면 다른 오일러 회로를 만든다.(1~3)번 반복
5. 여러개의 회로가 만들어지면 이를 적절하게 이어 붙인다.

실제 풀이한 코드
1. 아무 정점에서 시작.
2. DFS로 진행하며 갈 수 있는 곳에 stack push.
3. push하면서 arr의 간선의 개수를 빼준다.
4. 더이상 갈 곳이 없다면 answer에 넣는다.
*/


int arr[1001][1001] = {0};
stack<int> s;
vector<int> answer;

int main(){
  int n = 0;
  scanf("%d", &n);

  bool isable = true;
  int odd = 0;

  for(int i = 1; i <= n; i++){
    int temp = 0;
    for(int j = 1; j <= n; j++){
      scanf("%d", &arr[i][j]);
      temp += arr[i][j];
    }
    if(temp % 2 == 1)
      odd++;
  }

  if(odd > 1){
    printf("-1\n");
    return 0;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(arr[i][j] > 0){
        s.push(i);
        break;
      }
    }
    if(s.size() > 0)
      break;
  }

  while(!s.empty()){
    int now = s.top();

    for(int i = 1; i <= n; i++){
      if(arr[now][i] > 0){
        s.push(i);
        arr[now][i]--;
        arr[i][now]--;
        break;
      }
    }

    if(s.top() == now){
      s.pop();
      answer.push_back(now);
    }
  }

  for(int i = 0; i < answer.size(); i++)
    printf("%d ", answer[i]);
  return 0;
}
