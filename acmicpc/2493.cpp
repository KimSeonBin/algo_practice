#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

typedef struct tower{
  int h, i;
};

vector<tower> v;
stack<tower> s;

int answer[500001] = {0};

int main(){
  int n = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    tower temp;
    scanf("%d", &temp.h);
    temp.i = i+1;
    v.push_back(temp);
  }

  s.push(v[n-1]);

  for(int i = n-2; i >= 0; i--){
    tower temp = s.top();

    while(temp.h < v[i].h){
      answer[temp.i] = v[i].i;
      s.pop();

      if(s.size() == 0)
        break;
      temp = s.top();
    }
    s.push(v[i]);
  }

  for(int i = 1; i <= n; i++){
    printf("%d ", answer[i]);
  }
}
