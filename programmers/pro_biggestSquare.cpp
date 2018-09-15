#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001] = {0};
/*
ex)
1 1 1 1
1 1 1 1
0 1 1 1
0 0 1 0

->
dp[i][j]
1 2 3 4
1 2 3 4
0 1 2 3
0 0 1 0

for i in 0 ~ 행size:
  for j in 0 ~ 열size:
    count = 0
    v = dp[i][j] -> 행을 따라 내려가며 가질 수 있는 최대 길이
    1. dp[i+count][j]로 내려가며 count 증가
    2. v보다 작은 dp[i+count][j] 발견 시 v 갱신
*/
int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int min(int a, int b){
    if(a < b)
        return a;
    return b;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int br = board.size(), bc = board[0].size();
    for(int i = 0; i < br; i++){
        int count = 0;
        for(int j = 0; j < bc; j++){
            if(board[i][j] == 0){
                count = 0;
            }
            else{
                dp[i][j] = ++count;
            }
        }
    }

    for(int i = 0; i < br; i++){
        for(int j = 0; j < bc; j++){
            int count = 0, v = dp[i][j];
            if(answer >= dp[i][j] || dp[i][j] == 0)
                continue;
            if(i+answer >= br)
                continue;

            for(; count < v; count++){
                if(i+count >= br){
                    break;
                }
                if(count >= dp[i+count][j]){
                    break;
                }
                v = min(v, dp[i+count][j]);
            }

            answer = max(answer, count);
        }
    }

    answer *= answer;
    return answer;
}
