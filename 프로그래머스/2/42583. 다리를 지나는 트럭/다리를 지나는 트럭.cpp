#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    vector<int> finish;
    //큐에 넣을 때 나갈 시간을 넣고 저장한다.
    queue<int> on_the_B;
    //큐에 넣을 때 늘어날 무게 넣고 저장
    queue<int> W;
    int end_size = truck_weights.size();
    int i = 0;
    
    while(1)
    {
        //시간 1당 트럭 1대 처리
        time++;
        //다리 위에 트럭이 있다면
        if(!on_the_B.empty())
        {
            //나갈 수 있는 시간이 지났는가?
            //처음에 넣을 때 나갈때의 시간을 써뒀으니까 그냥 시간 추가 안하고 다 뺌
            //무게 다시 늘려놓기
            while(on_the_B.front() <= time &&!on_the_B.empty())
            {
                //finish 배열에 추가하고 버려
                finish.push_back(on_the_B.front());
                on_the_B.pop();
                weight += W.front();
                W.pop();
            }
        }
        //다리에 트럭이 올라갈 수 있나?
        if(on_the_B.size() < bridge_length)
        {
            if(truck_weights[i] <= weight)
            {
                on_the_B.push(time + bridge_length);
                W.push(truck_weights[i]);
                weight -= truck_weights[i];
                i++; //뒤 트럭으로
            }
        }
        if(finish.size() == end_size)
            break;
    }
    return time;
}