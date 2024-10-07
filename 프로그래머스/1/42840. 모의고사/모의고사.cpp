#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> vec3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int count1 = 0, count2 = 0, count3 = 0;

    for (size_t idx = 0; idx < answers.size(); ++idx) 
    {
        if (answers[idx] == vec1[idx % vec1.size()]) count1++;
        if (answers[idx] == vec2[idx % vec2.size()]) count2++;
        if (answers[idx] == vec3[idx % vec3.size()]) count3++;
    }
    
    // 점수를 쌍으로 저장
    vector<pair<int, int>> scores = 
    {
        {count1, 1},
        {count2, 2},
        {count3, 3}
    };

    // 점수(내림차순) 기준으로 정렬, 동점일 경우 키(오름차순) 기준으로 정렬
    sort(scores.begin(), scores.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });

    // 최고 점수를 가진 학생 추출
    vector<int> result;
    int highestScore = scores[0].first;

    for (const auto& score : scores) 
    {
        if (score.first == highestScore) 
        {
            result.push_back(score.second);
        }
    }

    return result;
}
