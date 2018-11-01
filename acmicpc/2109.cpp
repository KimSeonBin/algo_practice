#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct request{
  int deadline, pay, index;
  bool operator< (request a){
    if(pay == a.pay){
      if(deadline == a.deadline)
        return index < a.index;
      return deadline > a.deadline;
    }
    return pay > a.pay;
  }
};

vector<request> v;
int day[10001] = {0};

int main(){
  int n = 0, answer = 0;
  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    request temp;
    scanf("%d %d", &temp.pay, &temp.deadline);
    temp.index = i;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    if(day[v[i].deadline] == 0){
      day[v[i].deadline] = v[i].pay;
      continue;
    }

    for(int j = v[i].deadline-1; j > 0; j--){
      if(day[j] == 0){
        day[j] = v[i].pay;
        break;
      }
    }
  }

  for(int i = 1; i < 10001; i++)
    answer += day[i];
  printf("%d\n", answer);
  return 0;
}
