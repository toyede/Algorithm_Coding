#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Sosu(long long a)
{
    if(a == 0)
        return false;
    else if(a == 1)
        return false;
    else if(a == 2)
        return true;
    else
    {
        for(long long i = 2; i * i <= a; i++)
        {
            if(a%i == 0)
            {
                //소수가 아님
                return false;
            }
        }
        return true;
    }
}

int solution(int n, int k) {
    //진수 변환
    string f_step = "";
    while(n > 0)
    {
        f_step += to_string(n%k);
        n /= k;
    }
    reverse(f_step.begin(), f_step.end());
    //0이 나오면  open값 변화 근데 0다음 0이 나오는 경우는 변화 x
    bool open = true;
    vector<long long> sec_step;
    string temp = "";
    for(int i = 0; i < f_step.size(); i++)
    {
        if(open && f_step[i] != '0')
        {
            temp += f_step[i];
        }
        else if(open && f_step[i] == '0')
        {
            open = false;
            long long a;
            if(temp != "")
            {
                a = stoll(temp);
                sec_step.push_back(a);
            }
            temp = "";
        }
        else if(!open && f_step[i] != '0')
        {
            open = true;
            temp += f_step[i];
        }
        else
            continue;
    }
    //끝나고 만약 맨 끝이 0이 아니면 temp가 추가가 안되니까 마지막에 temp를 추가해줘야 함
    if(temp != "")
        sec_step.push_back(stoll(temp));
    int answer = 0;
    for(long long a : sec_step)
    {
        if(Sosu(a))
        {
            answer++;
        }
    }
    return answer;
}