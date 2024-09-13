#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<int>> lines) 
{
   vector<int> vec;
    for(const auto &l : lines)
    {
        for(int i=l[0]; i<l[1]; i++)
        {
            vec.push_back(i);
        }
    }
    
    unordered_map<int, int> frequencyMap;

    // 원소의 빈도를 계산합니다.
    for (int num : vec) 
    {
        frequencyMap[num]++;
    }

    int duplicateCount = 0;

    // 빈도가 2 이상인 원소의 수를 세는 방법
    for (const auto& pair : frequencyMap) 
    {
        if (pair.second > 1) 
        {
            duplicateCount++;
        }
    }

    return duplicateCount;
}
