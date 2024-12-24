#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) 
{
    vector<vector<char>> charBoard(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            charBoard[i][j] = board[i][j];
        }
    }

    int removedCount = 0;

    while (true) {
        set<pair<int, int>> removed;

        // 1. 블록 찾기
        for (int r = 0; r < m - 1; r++) {
            for (int c = 0; c < n - 1; c++) {
                if (charBoard[r][c] != '#' &&
                    charBoard[r][c] == charBoard[r][c+1] &&
                    charBoard[r][c] == charBoard[r+1][c] &&
                    charBoard[r][c] == charBoard[r+1][c+1]) {
                    removed.insert({r, c});
                    removed.insert({r, c+1});
                    removed.insert({r+1, c});
                    removed.insert({r+1, c+1});
                }
            }
        }

        if (removed.empty()) {
            break;
        }

        // 2. 블록 제거
        for (const auto& pos : removed) {
            charBoard[pos.first][pos.second] = '#';
        }
        removedCount += removed.size();

        // 3. 블록 이동
        for (int c = 0; c < n; c++) {
            int emptyIndex = m - 1;
            for (int r = m - 1; r >= 0; r--) {
                if (charBoard[r][c] != '#') {
                    charBoard[emptyIndex][c] = charBoard[r][c];
                    if (emptyIndex != r)
                        charBoard[r][c] = '#';
                    emptyIndex--;
                }
            }
        }
    }

    return removedCount;
}