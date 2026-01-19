#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    //n^2로 되는지 해보자 그냥
    //prices 앞에서부터 자기 뒤에 쭉 돌아봄
    //자기보다 작은거 발견 -> 그 번호 - 내 번호
    //끝까지 가면 size - 1 - i
    for(int i = 0; i < prices.size(); i++)
    {
        bool check = false;
        for(int j = i+1; j < prices.size(); j++)
        {
            if(prices[i] > prices[j])
            {
                answer.push_back(j - i);
                check  = true;
                break;
            }
        }
        if(check == false)
            answer.push_back(prices.size() - 1 - i);
    }
    return answer;
}