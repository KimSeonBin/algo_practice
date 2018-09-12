#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct pos{
    int x, y;
};

queue<pos> xy;
char map[32][32];
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            map[i][j] = board[i-1].at(j-1);
        }
    }

    while(true){
        int count = 0;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                char a = map[i][j], b = map[i+1][j], c = map[i][j+1], d = map[i+1][j+1];
                if(a == b && c == d && b == c && a != 'q'){
                    count++;
                    pos t;
                    t.x = i; t.y = j;
                    xy.push(t);
                }
            }
        }

        if(count == 0)
            break;

        while(!xy.empty()){
            pos p = xy.front(); xy.pop();
            map[p.x][p.y] = 'q';
            map[p.x][p.y+1] = 'q';
            map[p.x+1][p.y] = 'q';
            map[p.x+1][p.y+1] = 'q';
        }

        /*
        1,1      1,2
        2,1      2,2
        3,1
        4,1
        5,1
        6,1
        7,1
        */
        for(int i = 1; i <= n; i++){
            for(int j = m-1; j >= 1; j--){
                if(map[j][i] != 'q'){
                    char down = map[j][i];
                    for(int now = j+1; now <= m; now++){
                        if(map[now][i] == 'q'){
                            map[now][i] = map[now-1][i];
                            map[now-1][i] = 'q';
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(map[i][j] == 'q')
                answer++;
        }
    }
    return answer;
}
