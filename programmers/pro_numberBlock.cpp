#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    vector<int> prime;
    bool check[31623];

    for(int i = 2; i < 31623; i++){
        if(check[i])
            continue;
        prime.push_back(i);
        for(int j = i+i; j < 31623; j += i){
            check[j] = true;
        }
    }

    if(begin == 1){
        answer.push_back(0);
        begin++;
    }

    for(int i = begin; i <= end; i++){
        int whatdiv = 1;
        for(int j = 0; j < prime.size(); j++){
            if((i % prime[j]) != 0){
                continue;
            }
            if(i % prime[j] == 0 && i != prime[j]){
                whatdiv = prime[j];
                break;
            }
        }
        if(whatdiv == 1)
            answer.push_back(1);
        else
            answer.push_back(i / whatdiv);
    }
    return answer;
}
