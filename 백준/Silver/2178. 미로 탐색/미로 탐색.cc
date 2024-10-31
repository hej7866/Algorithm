#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

// 백준문제 - 미로 탐색 [2178]

/* 문제 [그래프]
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

/* 입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

/* 출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

/* 제한
*/

int n, m;
int graph[100][100];
int seen[100][100] = {0};

// 상, 우, 좌, 하로 이동
int dy[4] = {-1, 0, 0, 1}; 
int dx[4] = {0, 1, -1, 0}; 

void BFS()
{
    queue<pair<int, int>> q; // (y, x)
    q.push({0, 0});  // 미로 시작
    seen[0][0] = 1;  // 시작점에서의 거리를 1로 설정

    while(!q.empty())
    {
        int currY = q.front().first;
        int currX = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = currY + dy[i];
            int nx = currX + dx[i];

            // 미로 범위 내에서 이동 가능한 위치인지 확인
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(graph[ny][nx] == 0 || seen[ny][nx] != 0) continue;

            // 이동한 칸의 거리를 현재 칸 거리 + 1로 설정
            seen[ny][nx] = seen[currY][currX] + 1;
            q.push({ny, nx});
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string inputString;
        cin >> inputString;

        for(int j = 0; j < m; j++)
        {
            graph[i][j] = inputString[j] - '0';
        }
    }

    BFS();

    cout << seen[n-1][m-1] << "\n";  // 목표 위치까지의 최단 거리 출력
    
    return 0;
}