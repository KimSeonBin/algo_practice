/*
  tile[2] = 3
  tile[4] = 11 = 3*3 + 2 = tile[2]*3 + 2(새로운 타입의 채우기)
  tile[6] = 41 = 11 * 3 + 3 * 2(N=4타일 오른쪽 2칸 채우기)+ 2
  tile[8] = 153 = 41 * 3 + 11 * 2(N=4타일 오른쪽 4칸 채우기) + 3 * 2(N=6타일 오른쪽 2칸채우기) + 2
  tile[10]= 571 = 153*3 + 41*2(N=4타일 오른쪽 6칸채우기) + 11*2(N=6타일 오른쪽 4칸채우기) + 3*2(~~) + 2
 */


#include <stdio.h>

int main(){
  int n = 0;
  scanf("%d", &n);
  int tile[31] = {0};
  tile[0] = 1;
  tile[2] = 3;

  for(int i = 3; i <= n; i++){
    if(i % 2 == 0){
      tile[i] = tile[i-2] * 4 - tile[i-4];
    }

  }
  printf("%d\n", tile[n]);
  return 0;
}
