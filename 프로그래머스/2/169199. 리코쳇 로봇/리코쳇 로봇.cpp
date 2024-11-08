#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

// 이동할 방향 (상, 하, 좌, 우)
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

// BFS를 사용하여 최소 이동 횟수를 찾는 함수
int solution(vector<string> board) {
    int n = board.size();          // 게임판의 행 길이
    int m = board[0].size();       // 게임판의 열 길이
    int startX, startY, goalX, goalY;
    
    // 시작점(R)과 목표점(G)의 위치를 찾음
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') {
                startX = i;
                startY = j;
            }
            if (board[i][j] == 'G') {
                goalX = i;
                goalY = j;
            }
        }
    }
    
    // 방문 배열 초기화
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<tuple<int, int, int>> q; // 큐에 (x, y, 이동 횟수) 저장
    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        auto [x, y, moves] = q.front();
        q.pop();
        
        // 목표 위치에 도달했을 경우 이동 횟수 반환
        if (x == goalX && y == goalY) {
            return moves;
        }
        
        // 4개의 방향으로 이동
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x, ny = y;
            
            // 해당 방향으로 미끄러지며 이동 (장애물이나 벽에 부딪힐 때까지)
            while (true) {
                int tx = nx + dx[dir];
                int ty = ny + dy[dir];
                
                // 게임판을 벗어나거나 장애물을 만나면 멈춤
                if (tx < 0 || tx >= n || ty < 0 || ty >= m || board[tx][ty] == 'D') break;
                
                nx = tx;
                ny = ty;
            }
            
            // 이동한 위치가 방문한 적 없는 위치라면 큐에 추가
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, moves + 1});
            }
        }
    }
    
    // 목표 위치에 도달할 수 없는 경우
    return -1;
}
