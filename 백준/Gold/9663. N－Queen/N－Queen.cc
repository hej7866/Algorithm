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

// 백준문제 - N-Queen [9663]

/* 문제 [브루트포스 알고리즘 / 백트래킹]
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

/* 입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

/* 출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

/* 제한
*/

using namespace std;


vector<vector<int>> board;
int n;
int cnt = 0;


bool isSafe(int y, int x)
{
    // 같은 열에 퀸이 있는가?
    for(int i = 0; i < y; i++)
    {
        if(board[i][x] == 1) return false;
    }

    // 왼쪽 대각선 위에 퀸이 있는가?
    for(int i = y - 1, j = x - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1) return false;
    }

    // 오른쪽 대각선 위에 퀸이 있는가?
    for(int i = y - 1, j = x + 1; i >= 0 && j < n; i--, j++)
    {
        if(board[i][j] == 1) return false;
    }

    return true;
}

void nQueen(int y)
{
    if(y == n)
    {
        cnt++;
        return;
    }

    for(int x = 0; x < n; x++)
    {
        if(isSafe(y, x)) // 다른 퀸이랑 겹치지 않는다면
        {
            board[y][x] = 1; // 퀸을 배치한다
            nQueen(y + 1);   // 다음 행으로 이동한다
            board[y][x] = 0; // Backtrack: 퀸을 제거한다
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    board = vector<vector<int>>(n, vector<int>(n, 0));

    // n개의 퀸을 배치합니다. BT(Decision array)
    nQueen(0);

    cout << cnt << "\n";
    return 0;
}