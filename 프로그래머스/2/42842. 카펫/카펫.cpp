#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    //노란색으로 직사각형 또는 정사각형을 만듦.
    //항상 가로가 세로보다 길거나 같아야 함.
    //갈색의 개수 -> 갈색 직사각형 가로의 길이 * 2 + 노란 직사각형 세로 길이 * 2
    //이는 (노란 직사각형 가로길이 + 2) * 2 + 노란 직사각형 세로 길이 * 2
    //노란색의 개수 -> 노란 직사각형 가로 * 세로
    //yellow = Y_garo * Y_sero
    //Y_garo = yellow / Y_sero
    //Y_sero = yellow / Y_garo
    //brown = (Y_garo +2) * 2 + Y_sero * 2
    //brown = (Y_garo +2) * 2 +yellow/Y_garo * 2 -> 이 식으로 Y_가로 구하고 세로 구한 뒤 리턴
    //근의 공식으로 쁠마가 있는데 쁠이 가로로 씀.
    int Y_garo = (brown-4 + sqrt((4-brown)*(4-brown) - 16*yellow))/4;
    int Y_sero = yellow / Y_garo;
    
    int garo = Y_garo + 2;
    int sero = Y_sero + 2;
    vector<int> answer;
    answer.push_back(garo);
    answer.push_back(sero);
    
    return answer;
}