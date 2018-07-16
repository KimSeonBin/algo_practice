//http://blog.naver.com/PostView.nhn?blogId=infoefficien&logNo=220044637800&parentCategoryNo=&categoryNo=17&viewDate=&isShowPopularPosts=true&from=search
//http://sungwoo91.tistory.com/5
#include <stdio.h>
#include <vector>
using namespace std;
int primetemp[1121] = {0};
vector<int> prime;
int primelen = 0;
int main(){
  int test = 0;
  for(int i = 2; i < 1121; i++){
    if(primetemp[i] == 1){
      continue;
    }
    for(int j = 1; true; j++){
      if(i * j >= 1121){
        break;
      }
      primetemp[i*j] = 1;
    }
    prime.push_back(i);
    primelen++;
  }

  int answer2[15][1121] = {0};
  answer2[0][0]=1;
  for(int i = 0; i < primelen; i++){
    for(int j = 1120; j >= prime[i]; j--){
      for(int k = 1; k <= 14; k++){
        answer2[k][j] += answer2[k-1][j-prime[i]];
      }
    }
  }
  int n = 0, k = 0;
  scanf("%d", &test);
  for(int i = 0; i < test; i++){
    scanf("%d %d", &n, &k);
    printf("%d\n", answer2[k][n]);
  }
  return 0;
}
