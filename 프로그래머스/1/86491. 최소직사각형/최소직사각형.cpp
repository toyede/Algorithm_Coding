#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    //가로 배열
    //세로 배열
    //둘 다 정렬 -> 가로 기준 젤 큰거 세로 기준 젤 큰거
    //가로큰 세로큰 비교해서 더 큰거 선택, 그리고 가로 기준인지 세로 기준인지에 따라서
    //가로 기준이라면
    //세로를 정해야 하는데 세로같은 경우 원래 배열에서 가로가 큰지 세로가 큰지 본다음 작은거 기준으로 내림차순 정렬
    //그 배열 맨 앞에꺼 선택
    vector<int> garo;
    vector<int> sero;
    for(int i = 0; i < sizes.size(); i++)
    {
        garo.push_back(sizes[i][0]);
    }
    for(int i = 0; i < sizes.size(); i++)
    {
        sero.push_back(sizes[i][1]);
    }
    sort(garo.begin(), garo.end(), cmp);    //내림차순
    sort(sero.begin(), sero.end(), cmp);
    int garo_max = garo[0];
    int sero_max = sero[0];
    int max;
    vector<int> temp;
    int nam;
    if(garo_max > sero_max)
    {
        max = garo_max;
        for(int i = 0; i < sizes.size(); i++)
        {
            if(sizes[i][0] >= sizes[i][1])
                //가로가 더 긴 사각형 -> 돌려서 시도할 필요 없음. 세로 저장
                temp.push_back(sizes[i][1]);   
            else
                //세로가 더 긴 사각형 -> 돌려서 시도해보자. 가로 저장
                temp.push_back(sizes[i][0]);
        }
        sort(temp.begin(), temp.end(), cmp);
        //내림차순으로 보고 제일 큰거 선택 nam은거 선택
        nam = temp[0];
        return max*nam;
    }
        
    else
    {
        max = sero_max;
        //세로가 제일 클때 -> 가로랑 세로중 세로가 가로보다 작으면 돌려보려는 시도
        for(int i = 0; i < sizes.size(); i++)
        {
            //가로가 세로보다 클 때는 돌려보려는 시도를 해야 한다.
            if(sizes[i][0] >= sizes[i][1])
            {
                temp.push_back(sizes[i][1]);
            }
            else
                temp.push_back(sizes[i][0]);
        }
        sort(temp.begin(), temp.end(), cmp);
        //내림차순으로 보고 제일 큰거 선택 nam은거 선택
        nam = temp[0];
        return max*nam;
    }
}