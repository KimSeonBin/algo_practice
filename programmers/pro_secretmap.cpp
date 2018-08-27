#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int map[17][17] = {0};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            map[i][(n-1)-j] = arr1[i] % 2;
            arr1[i] /= 2;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            map[i][(n-1)-j] += arr2[i] % 2;
            arr2[i] /= 2;
        }
        string temp;
        for(int j = 0; j < n; j++){
            if(map[i][j] == 0){
                temp += ' ';
            }
            else{
                temp += '#';
            }
        }
        answer.push_back(temp);
    }
    return answer;
}
