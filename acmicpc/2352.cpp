#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct port{
  int a, b;
  bool operator< (port x){
    return b < x.b;
  }
};

vector<port> v;
stack<int> s;

int main(){
  int n = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    port temp; temp.a = i;
    scanf("%d", &temp.b);
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    if(s.size() == 0){
      s.push(v[i].a);
      continue;
    }

    stack<int> temp;

    while(true){
      if(s.size() == 0)
        break;

      if(s.top() > v[i].a){
        temp.push(s.top());
        s.pop();
      }
      else{
        break;
      }
    }
    
    s.push(v[i].a);

    if(temp.size() > 0)
      temp.pop();

    while(!temp.empty()){
      s.push(temp.top());
      temp.pop();
    }

  }

  printf("%d\n", s.size());
  return 0;
}
