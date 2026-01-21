#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    //우선순위 큐 활용
    //for문으로 우선순위 큐에 scoville에 있는거 집어 넣기
    //우선순위 큐 할 때 내림차순으로 되게 하기
    //작은거부터 -> greater, 큰거부터 -> less
    //맨 위에꺼 뽑기 두번 하고 섞어서 다시 푸쉬
    //while로 큐 사이즈가 > 1일 때만 하기
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int a : scoville)
    {
        pq.push(a);
    }
    int count = 0;
    while(pq.size() > 1)
    {
        if(pq.top() >= K)
            return count;
        int fst = pq.top();
        pq.pop();
        int sec = pq.top();
        pq.pop();
        int temp = fst + 2 * sec;
        pq.push(temp);
        count++;
    }
    if(pq.top() < K)
        return -1;
    else
        return count;
}