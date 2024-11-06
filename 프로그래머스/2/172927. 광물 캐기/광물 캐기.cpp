#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int minFatigue = INT_MAX;  // 최소 피로도 추적 변수
int fatigue[3][3] = {
    {1, 1, 1},    // 다이아 곡괭이
    {5, 1, 1},    // 철 곡괭이
    {25, 5, 1}    // 돌 곡괭이
};

// DFS 함수 정의
void dfs(vector<int>& picks, vector<string>& minerals, int pickIndex, int start, int currentFatigue) 
{
    // 현재 피로도가 이미 최소 피로도보다 크면 가지치기
    if (currentFatigue >= minFatigue) return;

    // 광물의 끝에 도달했거나 모든 곡괭이를 다 사용한 경우
    if (start >= minerals.size() || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)) 
    {
        minFatigue = min(minFatigue, currentFatigue);
        return;
    }

    // 곡괭이마다 가능한 경우를 탐색
    for (int i = 0; i < 3; i++) 
    {
        if (picks[i] > 0) 
        {
            picks[i]--;  // 곡괭이 사용

            // 현재 곡괭이로 광물 5개를 캐기
            int newFatigue = currentFatigue;
            for (int j = 0; j < 5 && (start + j) < minerals.size(); j++) 
            {
                int mineralType = 0;
                if (minerals[start + j] == "diamond") mineralType = 0;
                else if (minerals[start + j] == "iron") mineralType = 1;
                else mineralType = 2;

                newFatigue += fatigue[i][mineralType];
            }

            // 다음 광물 묶음으로 이동
            dfs(picks, minerals, i, start + 5, newFatigue);

            picks[i]++;  // 곡괭이 사용 복원
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) 
{
    dfs(picks, minerals, 0, 0, 0);
    return minFatigue;
}