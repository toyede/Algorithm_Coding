#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void makeNum(vector<char>& nums, vector<bool>& used, string ing, vector<string>& mn)
{
    for(int i = 0; i < nums.size(); i++)
    {
        //만약 썼다면 패스
        if(used[i]) continue;
        
        //선택하고 트루로 변환
        used[i] = true;
        
        mn.push_back(ing + nums[i]);
        
        makeNum(nums, used, ing + nums[i], mn);
        
        used[i] = false;
    }
}

bool is_sosu(int a)
{
    //2부터 n-1까지 나눠보고
    //만약 %n 이 0이라면 나눠 떨어지는게 1이랑 자기 자신 말고 있는거니까 제외
    if(a == 0)
        return false;
    if(a == 1)
        return false;
    if(a == 2)
        return true;
    
    
    bool check = false;
    for(int i = 2; i < a; i++)
    {
        if(a % i == 0)
            check = true;
    }
    if(check)
        return false;
    else
        return true;
}
int solution(string numbers) {
    //char로 바꿔서 배열 생성
    vector<char> nums;
    
    for(int i = 0; i < numbers.length(); i++)
    {
        nums.push_back(numbers[i]);
    }
    //숫자 만들 때 썼는지 안썼는지 판단하는 부울
    vector<bool> used(nums.size(), false);
    //만들어진 숫자 배열
    vector<string> mn;
    
    string ing = "";
    //재귀 함수로 숫자 생성
    makeNum(nums, used, ing, mn);
    //숫자로 변환하고 정렬하고 중복 제거 stoi하면 0011이 11로 처리됨
    vector<int> clear_int;
    
    for(string a : mn)
    {
        clear_int.push_back(stoi(a));
    }
    sort(clear_int.begin(), clear_int.end());
    //중복 제거 숫자가 117과 같이 같은 숫자가 있으면 중복이 생김
    clear_int.erase(unique(clear_int.begin(), clear_int.end()), clear_int.end());
    
    vector<int> sosu;
    for(auto& a : clear_int)
    {
        if(is_sosu(a))
        {
            sosu.push_back(a);
        }
    }
    
    
    int answer = sosu.size();
    return answer;
}