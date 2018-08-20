#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
test case
5
3 2 1 4 2
(2)

5
2 2 2 1 3
(2)

5
3 2 1 2 3
(3)

5
3 2 1 4 5
(3)

7
4 5 6 7 1 2 3
(4)
*/

typedef struct val{
  int index;
  int value;

  bool operator< (val a){
    if(value == a.value){
      return index < a.index;
    }
    return value < a.value;
  }
};

vector<val> v;

int main(){
  int n = 0, answer = 1;
  scanf("%d", &n);

  for(int i = 1; i <= n; i++){
    int t = 0;
    scanf("%d", &t);
    val temp;
    temp.index = i; temp.value = t;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());

  int temp = 1, nextindex = v[0].index, nextvalue = v[0].value;
  for(int i = 1; i < n; i++){
    if(v[i].value - nextvalue == 1){//차이가 1일 때
      if(v[i].index > nextindex){//nextindex보다 크면 nextindex, nextvalue 갱신(증가 수열 append)
        nextvalue = v[i].value;
        nextindex = v[i].index;
        temp++;
      }
      else{//차이가 1인데 nextindex보다 index가 작은 경우 nextindex보다 큰 index를 가지는 val이 있는지 확인
        int tempvalue = v[i].value;
        for(; i < n-1; i++){
          if(v[i+1].value == tempvalue){
            if(v[i+1].index > nextindex){//있다면 갱신(append)
              nextvalue = v[i].value;
              nextindex = v[i].index;
              temp++;
              break;
            }
          }
          else{//없다면 청산 후 새로운 수열 경우의 수 생각
            if(answer < temp)
              answer = temp;
            temp = 1;
            nextindex = v[i].index;
            nextvalue = v[i].value;
            break;
          }
        }
      }
    }
    else if((v[i].value - nextvalue) == 0){//차이가 0이면 건너뛴다.
      continue;
    }
    else{//2이상 차이나면 새로운 수열 경우의 수 생각
      if(answer < temp)
        answer = temp;

      temp = 1;
      nextindex = v[i].index;
      nextvalue = v[i].value;
    }
  }

  if(answer < temp)
    answer = temp;

  printf("%d\n", answer);
  return 0;
}
