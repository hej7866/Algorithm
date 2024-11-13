#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> countMap;

    // 1. 귤 크기별로 빈도 계산
    for (int size : tangerine) 
    {
        countMap[size]++;
    }

    // 2. 빈도 리스트 생성 및 정렬
    vector<int> frequencies;
    for (auto& pair : countMap) 
    {
        frequencies.push_back(pair.second);
    }
    sort(frequencies.rbegin(), frequencies.rend()); // 내림차순 정렬

    // 3. 최소 종류 계산
    int selected = 0; // 선택한 귤의 개수
    int typeCount = 0; // 선택한 종류의 수

    for (int freq : frequencies) 
    {
        selected += freq;
        typeCount++;
        if (selected >= k) break; // k개를 만족하면 종료
    }

    return typeCount;
}