#include <string>
#include <vector>
#include <queue>

using namespace std;

//숫자 뽑아내는 함수
int Ppop_int(string s)
{
     string temp = "";
    //string 배열 상 맨 앞은 영어 1은 공백 2부터 숫자
    for(int i = 2; i < s.length(); i++)
    {
        temp += s[i];
    }
    //temp를 stoi로 변환
    return stoi(temp);
}

//pq 뒤집어버리기
priority_queue<int, vector<int>, greater<int>> Reverse_q(priority_queue<int, vector<int>, less<int>> pq)
{
    priority_queue<int, vector<int>, greater<int>> reverse;
    while(!pq.empty())
    {
        int a = pq.top();
        reverse.push(a);
        pq.pop();
    }
    return reverse;
}
//원래대로
priority_queue<int, vector<int>, less<int>> Ori_q(priority_queue<int, vector<int>, greater<int>> pq)
{
    priority_queue<int, vector<int>, less<int>> reverse;
    while(!pq.empty())
    {
        int a = pq.top();
        reverse.push(a);
        pq.pop();
    }
    return reverse;
}

vector<int> solution(vector<string> operations) {
    priority_queue<int, vector<int>, less<int>> pq;
    
    //operations 수만큼 반복
    for(int i = 0; i < operations.size(); i++)
    {
        //만약 string의 맨 앞-> 0번 인덱스의 값이 I라면 삽입 -> Ppop_int 실행
        if(operations[i][0] == 'I')
        {
            int a = Ppop_int(operations[i]);
            //추출한 정수 push
            pq.push(a);
        }
        //만약 D라면 delete
        else
        {
            //만약 큐가 비었다면 pass
            if(pq.empty())
                continue;
            //만약 최댓값 삭제라면
            else if(operations[i][2] == '1')
            {
                pq.pop();
            }
            //최솟값 삭제라면
            else if(operations[i][2] =='-')
            {
                //pq 뒤집어 엎어버려
                //pq를 뒤집는 거는 아니고 잠시 쓸 reverse를 만들어둠
                priority_queue<int, vector<int>, greater<int>> rq;
                rq = Reverse_q(pq);
                //여기서 맨 위에꺼 삭제해버리고 다시 이걸 pq로 업데이트
                rq.pop();
                pq = Ori_q(rq);
            }
        }
    }
    priority_queue<int, vector<int>, greater<int>> rq;
    rq = Reverse_q(pq);
    if(pq.empty())
    {
        vector<int> a = {0,0};
        return a;
    }
        
    else
    {
        int max = pq.top();
        int min = rq.top();
        vector<int> a = {max, min};
        return a;
    }
}