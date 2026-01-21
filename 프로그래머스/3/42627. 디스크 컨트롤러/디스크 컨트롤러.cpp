#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Job
{
    int num;    //작업 번호
    int plz;    //요청 시간
    int doing;  //소요 시간
};

struct cmp
{
    bool operator()(Job a, Job b)
    {
        if(a.doing != b.doing)
            return a.doing > b.doing;
        else if(a.plz != b.plz)
            return a.plz > b.plz;
        else
            return a.num > b.num;
    }
};

int solution(vector<vector<int>> jobs) {
    //jobs를 job 타입으로 변환하고 priority큐에 넣기
    priority_queue<Job, vector<Job>, cmp> pq;
    int time = 0;
    
    //각 작업별 반환 시간
    vector<int> end_time;
    //jobs를 일단 요청 시간으로 정렬하기
    sort(jobs.begin(), jobs.end());
    //이 포인터가 jobs 끝까지 가면 while문 종료
    int point = 0;
    while(point < jobs.size() || !pq.empty())
    {
        while(point < jobs.size() && jobs[point][0] <= time)
        {
            Job a;
            a.num = point;
            a.plz = jobs[point][0];
            a.doing = jobs[point][1];
            pq.push(a);
            point++;
        }
        
        if(!pq.empty())
        {
            Job a = pq.top();
            time += a.doing;    //time에 소요 시간 더하기 -> 이게 종료 시점
            int temp = time - a.plz;   //이건 종료 시점 - 요청 시점 = 반환 시간
            end_time.push_back(temp);
            pq.pop();
        }
        //시간 증가
        else if(pq.empty())
            time++;
    }
    
    
    
    //end타임에 있는거다 더하고 사이즈로 나누기
    int total = 0;
    for(auto& a : end_time)
    {
        total += a;
    }
    
    int answer = total / end_time.size();
    return answer;
}