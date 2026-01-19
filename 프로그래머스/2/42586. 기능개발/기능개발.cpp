#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> works;
    vector<int> answer;
    //works에 번호 매기기
    for(int i = 0; i < progresses.size(); i++)
    {
        works.push(i);
    }
    
    while(!works.empty())
    {
        for(int i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i]; //노동
        }
        int exit = 0;
        while(!works.empty() && progresses[works.front()] >= 100)
        {
            exit++;
            works.pop();
        }
        if(exit != 0)
            answer.push_back(exit);
    }
    
    return answer;
}