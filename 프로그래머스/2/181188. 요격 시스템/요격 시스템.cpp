#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) 
{
    sort(targets.begin(), targets.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int missileCount = 0;
    double lastIntercept = -1.0;

    for (const auto& target : targets) 
    {
        int s = target[0];
        int e = target[1];

        // 현재 요격 미사일로 커버할 수 없는 구간이 있으면 새로 발사
        if (lastIntercept < s) 
        {
            lastIntercept = e - 0.5; // 개구간이므로 end 바로 직전에 요격 미사일을 발사
            missileCount++;
        }
    }

    return missileCount;
}