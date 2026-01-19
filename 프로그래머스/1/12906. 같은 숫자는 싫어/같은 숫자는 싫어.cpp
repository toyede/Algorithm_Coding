#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;
    
    for(auto& a : arr)
    {
        q.push(a);
    }
    int start = -1;
    while(!q.empty())
    {
        
        if(start == q.front())
            q.pop();
        else if(start != q.front())
        {
            answer.push_back(q.front()); //answer에 넣고
            start = q.front(); //업데이트하고
            q.pop(); //없애고
        }
    }

    return answer;
}