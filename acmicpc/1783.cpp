#include <cstdio>

using namespace std;

int min(int a, int b){
  if(a < b)
    return a;
  return b;
}

int main(){
  int n = 0, m = 0, answer = 0;
  scanf("%d %d", &n, &m);

  if(n == 1 || m == 1)
    answer = 1;
  else if(n == 2){//n이 2이면 2칸 위로, 아래로를 실행할 수 없다.
    answer = min(4, (m+1) / 2);// 4번 이상 움직이기 위해서는 움직일 수 있는 경우의 수를 모두 사용해야 하는데 사용하지 못하기에 최대 4칸 움직일 수 있다.
  }
  else if(m < 7){
    answer = min(4, m);
  }
  else{
    // 4번 이상 움직이기위해선 m >= 7, n >= 3는 되야한다.
    // 1, 2, 3, 4번 다 움직이면 오른쪽 +6
    answer = m - 2; //1, 2, 3, 4번 다 움직이면 오른쪽으로 +1, +2 유동적으로 움직일 수 있다.
  }

  printf("%d\n", answer);
  return 0;
}
