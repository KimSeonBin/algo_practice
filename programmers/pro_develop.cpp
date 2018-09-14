#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < speeds.size(); i++){
        int temp = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0)
            temp++;
        q.push(temp);
    }

    while(!q.empty()){
        int v = q.front(), a = 1; q.pop();
        while(!q.empty()){
            int temp = q.front();
            if(temp > v)
                break;
            q.pop();
            a++;
        }
        answer.push_back(a);
    }
    return answer;
}
