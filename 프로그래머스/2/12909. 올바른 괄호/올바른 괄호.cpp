#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> gual;
    for(int i = 0; i < s.size(); i++)
    {
        gual.push(s[i]);
    }
    while(!gual.empty())
    {   
        int start = 0;
        //닫는 괄호가 나오기 전에 여는 괄호가 나오면 안됨.
        if(gual.top() == '(')
            return false;
        
        start++;    // ) 개수 카운트 시작
        gual.pop(); // ")" 삭제
        while(start != 0 && !gual.empty())
        {
            if(gual.top() == ')')
            {
                start++;
                gual.pop();
                if(gual.empty())
                    break;
            }
            if(gual.top() == '(')
            {
                start--;
                gual.pop();
            }
        }
        if(start != 0)
            return false;
    }
    
    return true;
}