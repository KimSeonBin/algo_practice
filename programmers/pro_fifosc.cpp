#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = -1, coresize = cores.size();
    int s = 0, e = 250000000, m = 0;

    while (s <= e){
        bool over = false;
        int temp = 0;
        m = (s+e) / 2;
        for(int i = 0; i < coresize; i++){
            temp += (m / cores[i]) + 1;
            if(temp > n){
                over = true;
                break;
            }
        }
        if(over){
            e = m - 1;
            continue;
        }
        if(temp >= n){
            e = m - 1;
        }
        else{
            s = m + 1;
        }
    }
    if(answer == -1)
      answer = s;

    vector<int> check;
    int total = 0, beforetotal = 0;
    for(int i = 0; i < coresize; i++){
      if(answer % cores[i] == 0){
        check.push_back(i+1);
      }
      total += (answer / cores[i]) + 1;
      beforetotal += ((answer-1) / cores[i]) + 1;
    }
    if(answer == 0)
        beforetotal = 0;
    answer = check[n - (beforetotal + 1)];
    return answer;
}
