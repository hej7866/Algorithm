#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> str_list) 
{
    // "l" 또는 "r"가 처음 나타나는 위치
    auto it = find_if(str_list.begin(), str_list.end(),
                      [](const string& s){ return s == "l" || s == "r"; });

    if (it == str_list.end()) return {};            // l/r 없으면 빈 벡터
    if (*it == "l") return {str_list.begin(), it};  // l이면 왼쪽만
    return {next(it), str_list.end()};              // r이면 오른쪽만
}