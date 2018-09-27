#include <string>
#include <vector>
#define moduler 1000000007
using namespace std;

int map[101][101] = {0};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i = 0; i < puddles.size(); i++){
        map[puddles[i][0]][puddles[i][1]] = -1;
    }

    for(int i = 2; i <= m; i++){
        if(map[i][1] == -1)
            break;
        map[i][1] = 1;
    }
    for(int i = 2; i <= n; i++){
        if(map[1][i] == -1)
            break;
        map[1][i] = 1;
    }

    for(int i = 2; i <= m; i++){
        for(int j = 2; j <= n; j++){
            if(map[i][j] == -1)
                continue;

            int up = map[i-1][j], left = map[i][j-1];
            if(up == -1)
                up = 0;
            if(left == -1)
                left = 0;

            map[i][j] = (up + left) % moduler;
        }
    }

    answer = map[m][n];
    return answer;
}
