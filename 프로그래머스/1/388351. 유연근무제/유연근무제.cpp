#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int day = startday;
    //희망시간 + 10 해서 다시 연산해서 정리한 스케줄 벡터
    //만약 10을 더할 때 나머지가 50 이상일 경우 +50을 한다.
    vector<int> hope_schedules;
    int people = schedules.size();
    vector<bool> Victory(people, true);
    for(auto& a : schedules)
    {
        if(a % 100 >= 50)
        {
            hope_schedules.push_back(a + 50);
        }
        else
            hope_schedules.push_back(a + 10);
    }
    for(int i = 0; i < people; i++)
    {
        //각 사람마다 1주일 검사
        day = startday;
        for(int j = 0; j < 7; j++)
        {
            if(day == 6 || day == 7)    //주말이면
                day++;
            else
            {
                //출근 시간 - 출근 희망 시간 > 10이면 실패
                if(timelogs[i][j] - hope_schedules[i] > 0)
                {
                    Victory[i] = false;
                    break;
                }
                day++;
            }
            if(day >= 8)
                day = 1;
        }
    }
    int answer = 0;
    for(const auto& a : Victory)
    {
        if(a == true)
            answer++;
    }
    
    return answer;
}