#include <stdio.h>
#include <vector>
using namespace std;


int main(){
  int n = 0, m = 0;
  int temp = 0;
  vector<int> lesson;
  int min = 1, max = 2000000000, mid = 0;
  int answer = 0;

  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    lesson.push_back(temp);
    if(min < temp){
      min = temp;
    }
  }

  int sum = 0, m_count = 0;
  while(min <= max){
    sum = 0;
    mid = (min + max) / 2;
    m_count = 0;
    for(int i = 0; i < n; i++){
      sum += lesson[i];
      if(sum > mid){
        m_count++;
        sum = lesson[i];
      }
    }
    if(m_count <= m - 1){
      max = mid - 1;
    }
    else{
      min = mid + 1;
    }
  }

  printf("%d\n", min);
  return 0;
}
