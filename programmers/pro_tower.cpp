#include <string>
#include <vector>
#include <stack>
using namespace std;

typedef struct signal{
    int index, power;
};
stack<signal> s;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    answer.assign(heights.size(), 0);

    signal a;
    a.index = heights.size(); a.power = heights[a.index-1];
    s.push(a);

    for(int i = heights.size()-2; i >= 0; i--){
        while(!s.empty()){
            signal temp = s.top();
            if(heights[i] > temp.power){
                s.pop();
                answer[temp.index-1] = i+1;
            }
            else
                break;
        }
        signal news;
        news.index = i+1; news.power = heights[i];
        s.push(news);
    }
    return answer;
}
