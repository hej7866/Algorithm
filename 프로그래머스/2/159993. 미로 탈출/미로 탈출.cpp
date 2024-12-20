#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int bfs(const vector<string>& maps, pair<int, int> start, char target) {
    int rows = maps.size();
    int cols = maps[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<tuple<int, int, int>> q; // (row, col, distance)
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    int dr[] = {-1, 1, 0, 0}; // 상하좌우
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c, dist] = q.front();
        q.pop();

        // 목표 지점 도달
        if (maps[r][c] == target) {
            return dist;
        }

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
                !visited[nr][nc] && maps[nr][nc] != 'X') {
                visited[nr][nc] = true;
                q.push({nr, nc, dist + 1});
            }
        }
    }

    return -1; // 목표 지점에 도달할 수 없음
}

int solution(vector<string> maps) {
    pair<int, int> start, lever, exit;

    // 시작점(S), 레버(L), 출구(E)의 위치 찾기
    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'S') start = {i, j};
            if (maps[i][j] == 'L') lever = {i, j};
            if (maps[i][j] == 'E') exit = {i, j};
        }
    }

    // S -> L 거리
    int toLever = bfs(maps, start, 'L');
    if (toLever == -1) return -1;

    // L -> E 거리
    int toExit = bfs(maps, lever, 'E');
    if (toExit == -1) return -1;

    return toLever + toExit;
}
