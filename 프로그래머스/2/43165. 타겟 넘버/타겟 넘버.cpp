#include <string>
#include <vector>

using namespace std;


vector<vector<int>> sign_array;

void generateSign(int n, vector<int>& current_signs)
{
    if(current_signs.size() == n)
    {
        //끝까지 다 부호 할당되었다면 저장
        sign_array.push_back(current_signs);
        return;
    }
    
    //+1
    current_signs.push_back(1);
    generateSign(n, current_signs);
    current_signs.pop_back();

    //-1
    current_signs.push_back(-1);
    generateSign(n, current_signs);
    current_signs.pop_back();
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> current_signs;
    
    //부호 배열 생성
    generateSign(numbers.size(), current_signs);
    
    //원본 * 부호 배열 -> 배열에 있는거 다 더하기
    for(const auto& array : sign_array)
    {
        int current_sum = 0;
        for(int i = 0; i < numbers.size(); i++)
        {
            current_sum += numbers[i] * array[i];
        }
        
        if(current_sum == target)
        {
            answer++;
        }
    }

    return answer;
}