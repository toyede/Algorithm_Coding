#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Dungeon(int k, vector<vector<int>>& dungeons, vector<bool>& visited, int count, vector<int>& clear_dun)
{
    
    for(int i = 0; i < dungeons.size(); i++)
    {
        if(visited[i] == true) continue;
        
        if(k >= dungeons[i][0]) //입장조건 충족?
        {
            visited[i] = true;
            Dungeon(k - dungeons[i][1], dungeons, visited, count + 1, clear_dun);
            visited[i] = false;
        }
    }
    clear_dun.push_back(count);
}

int solution(int k, vector<vector<int>> dungeons) {
    //숫자 만들때 처럼 재귀로 모든 경우의 수 다 해보고
    //각 경우의 수 마다 돈 던전 수 배열에 저장하고
    //정렬해서 배열 끝 값 리턴
    vector<int> clear_dun;
    vector<bool> visited(dungeons.size(), false);
    int count = 0;
    Dungeon(k, dungeons, visited, count, clear_dun);
    sort(clear_dun.begin(), clear_dun.end());
    
    int answer = clear_dun.back();
    return answer;
}