#include <string>
#include <vector>

using namespace std;

void connected(int computer_name, int n, vector<vector<int>>& computers, vector<bool>& checklist)
{
    //i에 연결된 j 컴퓨터 이름을 전달 받음.
    int j = computer_name;
    //computer_name 체크리스트 1로 변경, 덮어씌워도 상관 없음
    checklist[j] = 1;
    
    //j번 컴퓨터에 연결된 것들 순회 computer[j][?]
    for(int next = 0; next < n; next++)
    {
        //자기 자신 pass
        if(j == next)
            continue;
        if(computers[j][next] == 1 && checklist[next] == 0)
        {
            connected(next, n, computers, checklist);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    //체크리스트 기본 0으로 세팅
    vector<bool> checklist(n, false);
    int answer = 0;
    
    //n번 컴퓨터
    for(int i = 0; i < n; i++)
    {
        //computers[i][j]의 j 순회
        //근데 자기 자신은 별도로 처리해야 하나?
        //i == j 면 넘어가기
        //i가 체크리스트에서 체크가 된거라면
        //connected에서 검사되어서 확인할 필요가 없는 컴퓨터이니까 패스
        
        if(checklist[i] == 1)
            continue;
        
        checklist[i] = 1;
        //새로운 덩어리 시작
        answer++;
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            
            //만약 i랑 j가 직접 연결되어있다면
            if(computers[i][j] == 1)
            {
                connected(j, n, computers, checklist);
            }
        }
    }
    return answer;
}