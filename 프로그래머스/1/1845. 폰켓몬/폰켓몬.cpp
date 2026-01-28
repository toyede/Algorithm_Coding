#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int N = nums.size();
    unordered_set<int> mon;
    for(auto const a : nums)
    {
        mon.insert(a);
    }
    int size = mon.size();
    if(size > N/2)
    {
        answer = N/2;
    }
    else
        answer = size;
    return answer;
}