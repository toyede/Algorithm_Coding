#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    vector<int> servers(24, 0);
    int answer = 0;
    
    //플레이어수/m 이 서버수보다 크면 증설해야함
    for(int i = 0; i < players.size(); i++)
    {
        if(players[i]/m > servers[i])
        {
            //몇개 증설해야하는지 -> players[i]/m - servers[i] 만큼 증설해야함
            int plus = players[i]/m - servers[i];
            //이 값은 answer에 추가해줘야 함
            answer += plus;
            //증설한 서버개수를  i 시간부터 k 시간만큼 반복하여 벡터에 추가
            for(int time = i; time < i + k; time++)
            {
                if(time > servers.size())
                    break;
                servers[time] += plus;
            }
        }
    }
    return answer;
}