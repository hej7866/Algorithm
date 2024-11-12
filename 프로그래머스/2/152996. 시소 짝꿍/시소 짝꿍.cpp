#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights)
{
    unordered_map<int, int> weightMap;
    long long count = 0;

    // 가능한 비율을 모두 포함합니다.
    vector<pair<int, int>> ratios = 
    {
        {1, 1},
        {2, 3}, {3, 2},
        {2, 4}, {4, 2},
        {3, 4}, {4, 3}
    };

    // 몸무게를 정렬하여 동일한 몸무게를 가진 사람들을 인접하게 배치합니다.
    sort(weights.begin(), weights.end());

    for (int weight : weights)
    {
        for (auto ratio : ratios)
        {
            int numerator = ratio.first;
            int denominator = ratio.second;

            // 정수 연산을 위해 분모로 나누어 떨어지는 경우만 고려
            if ((weight * numerator) % denominator == 0)
            {
                int adjustedWeight = (weight * numerator) / denominator;

                // adjustedWeight가 이미 weightMap에 있다면, 가능한 짝꿍이 존재합니다.
                if (weightMap.count(adjustedWeight) > 0)
                {
                    count += weightMap[adjustedWeight];
                }
            }
        }

        // 현재 몸무게를 해시맵에 추가합니다.
        weightMap[weight]++;
    }

    return count;
}