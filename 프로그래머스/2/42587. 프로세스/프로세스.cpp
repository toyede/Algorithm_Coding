#include <string>
#include <vector>
#include <queue>
#include <algorithm>

bool compare(int a, int b)
{
    return a > b;
}

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue <int> sorted_q;
    queue <int> q;
    queue <int> name_q;
    
    vector<int> sorted_priorities = priorities;
    sort(sorted_priorities.begin(), sorted_priorities.end(), compare);
    
    for(auto& sq : sorted_priorities)
    {
        sorted_q.push(sq);
    }
    for(auto& a : priorities)
    {
        q.push(a);
    }
    for(int i = 0; i < priorities.size(); i++)
    {
        name_q.push(i);
    }
    
    while(1)
    {
        
       
        if(q.front() == sorted_q.front())
        {
            if(name_q.front() == location)
                return answer;
            
            answer++;
            q.pop();
            name_q.pop();
            sorted_q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
            name_q.push(name_q.front());
            name_q.pop();
        }
        if(q.empty())
            break;
    }
}