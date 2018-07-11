#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n = 0, m = 0, temp = 0;
  vector<int> card;
  vector<int> request;

  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf(" %d", &temp);
    card.push_back(temp);
  }
  sort(card.begin(), card.end());

  scanf(" %d", &m);
  int start = 0, end = n-1, mid = (n-1)/2;
  bool check = false;
  for(int i = 0; i < m; i++){
    scanf(" %d", &temp);
    request.push_back(temp);
  }
  for(int i = 0; i < m; i++, start = 0, end = n-1, mid = (n-1)/2, check = false){
    temp = request[i];
    while(start <= end){
      if(card[mid] < temp){
        start = mid+1;
        mid = (start + end) / 2;
      }
      else if(card[mid] > temp){
        end = mid-1;
        mid = (start + end) / 2;
      }
      else{
        check = true;
        printf("1 ");
        break;
      }
    }
    if(!check){
      printf("0 ");
    }
  }
  printf("\n");
  return 0;
}
