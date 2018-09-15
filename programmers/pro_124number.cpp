#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int ton = 0, temp = 3;

    while(true){
        if(ton + temp >= n)
            break;
        ton += temp;
        temp *= 3;
    }

    while(temp > 0){
        temp /= 3;
        for(int i = 1; i <= 3; i++){
            if(ton + temp * (i-1) < n && n <= ton + temp * i){
                if(i == 1)
                    answer += '1';
                else if(i == 2)
                    answer += '2';
                else
                    answer += '4';
                n -= temp * i;
                ton -= temp;
                break;
            }
        }
    }

    return answer;
}
