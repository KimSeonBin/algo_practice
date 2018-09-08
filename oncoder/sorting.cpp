#include<stdio.h>
#include <vector>
#include <algorithm>
//2018.09.08
//시험이 끝난 후 풀이가 생각나 쓴 코드이기에 답인지는 확실하지 않습니다.

vector<int> sorting(vector<int> element){
  sort(element.begin(), element.end());

  vector<int> answer;
  int ele_size = element.size();
  bool check[51];

  /*
  while answer_size < n:
  element 처음부터 반복. element[j] - element[i] > 2가 있는 i 선택(j > i)
  answer push(i)

  O(n^3)
  */
  for(int i = 0; i < ele_size; i++){
    int index = -1;
    bool c = false;
    for(int j = 0; j < ele_size; j++){
      if(!check[j]){
        index = j;//마지막 element의 경우도 생각해 index 상시 갱신
        for(int k = j+1; k < ele_size; k++){
          if(element[k] - element[j] > 1){
            c = true;
            break;
          }
        }
        if(c)//element[j] - element[i] > 1를 찾았으니 stop
          break;
      }
    }
    answer.push_back(element[index]);
    check[index] = true;
  }
  return answer;
}


int main(){
  vector<int> a = {4,5,6,7};
  vector<int> an = sorting(a);
  for(int i = 0; i < a.size(); i++){
    printf("%d ", an[i]);
  }
  printf("\n");
  return 0;
}
