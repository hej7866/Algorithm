#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) 
{
    
    vector<pair<int, int>> pairedVec;
    for (int x : numlist) 
    {
        int distance = abs(x - n);
        pairedVec.emplace_back(distance, x);
    }

    // 거리 기준으로 오름차순 정렬, 거리 같으면 값 기준으로 내림차순 정렬
    sort(pairedVec.begin(), pairedVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
            {
                if (a.first != b.first) 
                {
                    return a.first < b.first; // 거리 기준 오름차순
                }
                return a.second > b.second; // 값 기준 내림차순
            }
        );

    // 정렬된 쌍을 원래 벡터에 복사
    for (size_t i = 0; i < numlist.size(); ++i) 
    {
        numlist[i] = pairedVec[i].second;
    }
    return numlist;
}
