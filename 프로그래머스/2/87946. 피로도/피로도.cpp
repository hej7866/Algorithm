#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDungeons = 0;

void backtrack(int k, int count, const vector<vector<int>>& dungeons, vector<bool>& visited) {
    maxDungeons = max(maxDungeons, count); // 최대 탐험 던전 수 갱신

    for (int i = 0; i < dungeons.size(); ++i) {
        if (!visited[i] && k >= dungeons[i][0]) { // 던전 탐험 가능 여부 확인
            visited[i] = true; // 현재 던전 방문 처리
            backtrack(k - dungeons[i][1], count + 1, dungeons, visited); // 재귀 호출
            visited[i] = false; // 백트래킹: 방문 처리 해제
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    backtrack(k, 0, dungeons, visited);
    return maxDungeons;
}