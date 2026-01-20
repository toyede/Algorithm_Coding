#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    //답 맞춘 수 배열
    vector<int> answer; 
    //1번 패턴
    //0~4 -> 5로 나눈 나머지
    vector<int> fst_p = {1,2,3,4,5};
    
    //2번 패턴
    //0~7 -> 8로 나눈 나머지
    vector<int> sec_p = {2,1,2,3,2,4,2,5};
    //3번 패턴
    //10으로 나눈 나머지
    vector<int> thd_p = {3,3,1,1,2,2,4,4,5,5};
    
    //패턴을 통해 사람마다 답지 제작
    vector<int> fst_dap, sec_dap, thd_dap;
    int i = 0;
    while(i < answers.size())
    {
        fst_dap.push_back(fst_p[i%5]);
        sec_dap.push_back(sec_p[i%8]);
        thd_dap.push_back(thd_p[i%10]);
        i++;
    }
    //1번 채점 -> answer에 추가
    int fst_correct = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        if(fst_dap[i] == answers[i])
            fst_correct++;
    }
    int sec_correct = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        if(sec_dap[i] == answers[i])
            sec_correct++;
    }
    int thd_correct = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        if(thd_dap[i] == answers[i])
            thd_correct++;
    }
    answer.push_back(fst_correct);
    answer.push_back(sec_correct);
    answer.push_back(thd_correct);
    int max = 0;
    for(auto& a : answer)
    {
        if(a > max)
            max = a;
    }
    vector<int> result;
    for(int i = 0; i < answer.size(); i++)
    {
        if(answer[i] == max)
            result.push_back(i+1);
    }
    return result;
}