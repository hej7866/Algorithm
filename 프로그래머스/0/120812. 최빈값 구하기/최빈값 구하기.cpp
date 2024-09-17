#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> array) 
{
    map<int, int> arrMap;
    

    for(int num : array)
    {
        arrMap[num]++;
    }

    int maxFrequency = 0;
    vector<int> mostFrequentNumbers;

    // 가장 높은 빈도를 찾고, 해당 빈도를 가진 모든 숫자를 추적
    for (const auto& pair : arrMap) 
    {
        if (pair.second > maxFrequency) 
        {
            maxFrequency = pair.second;
            mostFrequentNumbers.clear(); // 새로운 최빈값이 발견되면 기존 리스트를 비운다
            mostFrequentNumbers.push_back(pair.first);
        } 
        else if (pair.second == maxFrequency) 
        {
            mostFrequentNumbers.push_back(pair.first); // 같은 빈도의 숫자 추가
        }
    }
    
    if (mostFrequentNumbers.size() > 1) 
    {
        return -1;
    }
    else
    {
        return mostFrequentNumbers[0];
    }
}