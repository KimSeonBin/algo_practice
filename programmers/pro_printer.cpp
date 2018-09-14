#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct paper{
    int index, p;
};

int count[11];
int paperindex[101];

queue<paper> q;

int solution(vector<int> priorities, int location) {
    int answer = 0, index = 1;
    for(int i = 0; i < priorities.size(); i++){
        for(int j = 1; j < priorities[i]; j++){
            count[j]++;
        }
        paper p;
        p.index = i; p.p = priorities[i];
        q.push(p);
    }

    while(!q.empty()){
        paper p = q.front(); q.pop();
        if(count[p.p] == 0){
            paperindex[p.index] = index++;
            for(int j = 1; j < p.p; j++)
                count[j]--;
        }
        else{
            q.push(p);
        }
    }

    answer = paperindex[location];
    return answer;
}
