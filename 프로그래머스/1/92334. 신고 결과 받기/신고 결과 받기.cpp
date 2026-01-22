#include <string>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<vector<string>> Users;
    for(string s : id_list)
    {
        Users.push_back({s});
    }
    //2차원 배열로 00 - 00, 00, 00, 00 이런 식으로 유저별 신고한 놈들 주르륵
    //공백으로 문자열 자르고 첫번째꺼로 어디에 추가할지 두번째로 거기에 두번째 이름 추가하기
    for(int i = 0; i < report.size(); i++)
    {
        string fst;
        string sec;
        stringstream ss(report[i]);
        ss >> fst;
        ss >> sec;
        //fst 이름을 Users 몇번째에 있는지 찾기
        for(int j = 0; j < Users.size(); j++)
        {
            if(fst == Users[j][0])
            {
                //만약 이 사람이 같은 사람을 신고 여러번 했다면 추가 안하고 처음이면 추가
                bool check = false;
                for(int k = 0; k < Users[j].size(); k++)
                {
                    if(sec == Users[j][k])
                    {
                        check = true;
                        break;
                    }
                }
                if(!check)
                    Users[j].push_back(sec);
            }
        }
    }
    
    //신고당한놈들 배열 따로 생성 -> 거기에 횟수 저장하고 그 횟수가 k보다 크면 
    //Users 배열에 가서 그 이름이 k에 있는지 확인하고
    //Users[i][k]
    //있으면 answer[i]++
    vector<int> answer(id_list.size(), 0);
    vector<int> bad_count(id_list.size(), 0);
    
    for(int i = 0; i < Users.size(); i++)
    {
        //Users[i][0]은 자기자신
        for(int j = 1; j < Users[i].size(); j++)
        {
            for(int k = 0; k < id_list.size(); k++)
            {
                if(Users[i][j] == id_list[k])
                {
                    bad_count[k]++;
                }
            }
        }
    }
    
    for(int z = 0; z < bad_count.size(); z++)
    {
        if(bad_count[z] >= k)
        {
            //이놈의 이름은 id_list[i] 이걸 Users에서 [i][] 에있는지 보고 있으면 answer[i]++
            for(int i = 0; i < Users.size(); i++)
            {
                for(int j = 1; j < Users[i].size(); j++)
                {
                    if(Users[i][j] == id_list[z])
                    {
                        answer[i]++;
                    }
                }
            }
        }
    }
    
    return answer;
}