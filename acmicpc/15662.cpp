#include <iostream>
#include <vector>
#include <string>

using namespace std;

char wheel[1001][10];
/*1: N, 2: NE, 3: E, 4: SE, 5: E, 6: WE, 7: W, 8: NW*/
int main(){
  int t = 0;
  cin >> t;

  for(int i = 1; i <= t; i++){
    string temp;
    cin >> temp;
    for(int j = 1; j <= temp.size(); j++){
      wheel[i][j] = temp.at(j-1);
    }
  }

  int k = 0;
  cin >> k;
  for(int i = 0; i < k; i++){
    int num = 0, d = 0;
    //d: 1-> 시계, -1-> 반시계
    cin >> num >> d;

    int temp[1001] = {0};
    temp[num] = d;
    for(int j = num+1; j <= t; j++){
      if(temp[j-1] == 1){
        if(wheel[j-1][3] != wheel[j][7]){
          temp[j] = -1;
        }
      }
      else if(temp[j-1] == -1){
        if(wheel[j-1][3] != wheel[j][7]){
          temp[j] = 1;
        }
      }
      else{
        break;
      }
    }
    for(int j = num-1; j >= 1; j--){
      if(temp[j+1] == 1){
        if(wheel[j][3] != wheel[j+1][7]){
          temp[j] = -1;
        }
      }
      else if(temp[j+1] == -1){
        if(wheel[j][3] != wheel[j+1][7]){
          temp[j] = 1;
        }
      }
      else{
        break;
      }
    }

    for(int j = 1; j <= t; j++){
      if(temp[j] == 0)
        continue;

      if(temp[j] == 1){
        for(int temp = 8; temp >= 1; temp--){
          wheel[j][temp+1] = wheel[j][temp];
        }
        wheel[j][1] = wheel[j][9];
      }
      else{
        for(int temp = 1; temp <= 8; temp++){
          wheel[j][temp-1] = wheel[j][temp];
        }
        wheel[j][8] = wheel[j][0];
      }
    }
  }

  int answer = 0;
  for(int i = 1; i <= t; i++){
    if(wheel[i][1] == '1')
      answer++;
  }

  printf("%d\n", answer);
  return 0;
}
