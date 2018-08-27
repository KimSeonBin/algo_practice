#include <string>
using namespace std;
int score[4];

int solution(string dartResult) {
    int answer = 0;
    int resultlen = dartResult.size(), sdt = 1;

    for(int i = 0; i < resultlen; i++){
        char temp = dartResult.at(i);
        if(temp >= 48 && temp <= 58){//number 0~10
            if(score[sdt] == 0)
                score[sdt] = temp - 48;
            else
                score[sdt] = 10;
        }
        else{//S, D, T, * #
            if(temp == 'S'){//1제곱
                sdt++;
            }
            else if(temp == 'D'){//2제곱
                score[sdt++] = score[sdt] * score[sdt];
            }
            else if(temp == 'T'){//3제곱
                score[sdt++] = score[sdt] * score[sdt] * score[sdt];
            }
            else if(temp == '*'){
                score[sdt-1] *= 2;
                if(sdt-2 == 0)
                    continue;
                score[sdt-2] *= 2;
            }
            else{
                score[sdt-1] *= -1;
            }
        }
    }

    for(int i = 1; i < 4; i++)
        answer += score[i];

    return answer;
}
