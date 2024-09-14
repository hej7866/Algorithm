#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board) 
{
    vector<vector<int>> boardX = board;
    
    int n = boardX.size();
    for(int r=0; r < n; r++)
    {
        for(int c=0; c < n; c++)
        {
            if(boardX[r][c] == 1)
            {
                // 범위를 지정하여 업데이트
                for (int i = max(0, r - 1); i <= min(n - 1, r + 1); i++) 
                {
                    for (int j = max(0, c - 1); j <= min(n - 1, c + 1); j++) 
                    {
                        if(boardX[i][j] != 1)
                        { 
                            boardX[i][j] = 2;
                        }
                    }
                }
            }
        }
    }
    int count = 0;
    for(auto &v : boardX)
    {
        for(int &i : v)
        {
            if(i == 0)
            {
                count++;
            }
            cout << i << " ";
        }
        cout << endl;
    }
    return count;
}