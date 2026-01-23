#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    //나누어 떨어질 때 층 -1 만약 안나눠 떨어지면 그대로
    int total_F;    //총 층
    if(n%w == 0)
        total_F = n/w;
    else
        total_F = n/w + 1;
    
    int my_F;       //내가 위치한 층
    if(num%w == 0)
        my_F = num/w;
    else
        my_F = num/w + 1;
    
    int my_spot;//내가 위치한 칸이 왼쪽에서 몇번째?
    if(my_F % 2 == 0)  //짝수층
    {
        if(num % w == 0) //나눠 떨어지면 가장 왼쪽 1번
            my_spot = 1;
        else
            my_spot = w - (num%w) + 1;
    }
       
    else //홀수층
    {
       if(num % w == 0)
        {
            my_spot = w;
        } 
        else
            my_spot = num%w;
    }
    
    int top_count;    //꼭대기 층에 블럭 왼쪽에서부터 몇개 있지? -> 이것도 홀수일떄 이거
    int answer = 0;
    if(total_F % 2 == 0)  //total이짝수
    {
        if(n%w == 0)
            top_count = 1;
        else
            top_count = w - (n%w) + 1;
        
        if(my_spot >= top_count)
        {
            answer = total_F - my_F + 1;
        }
        else
            answer = total_F - my_F;
    }
    else  //홀수층
    {
        if(n%w == 0)
            top_count = w;
        else
            top_count = n%w;
        
        if(my_spot <= top_count)
        {
            answer = total_F - my_F +1;
        }
        else
            answer = total_F - my_F;
    }
    
    
    return answer;
}