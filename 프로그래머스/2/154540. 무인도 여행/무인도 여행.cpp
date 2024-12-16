#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// DFS 함수
void dfs(vector<string>& maps, vector<vector<bool>>& visited, int r, int c, int& sum) {
    int rows = maps.size();
    int cols = maps[0].size();

    if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c] || maps[r][c] == 'X') {
        return;
    }

    visited[r][c] = true;
    sum += (maps[r][c] - '0');

    dfs(maps, visited, r + 1, c, sum);
    dfs(maps, visited, r - 1, c, sum);
    dfs(maps, visited, r, c + 1, sum);
    dfs(maps, visited, r, c - 1, sum);
}


vector<int> solution(vector<string> maps) {
    int rows = maps.size();
    int cols = maps[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<int> answer;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (maps[r][c] != 'X' && !visited[r][c]) {
                int sum = 0;
                dfs(maps, visited, r, c, sum);
                answer.push_back(sum);
            }
        }
    }
    
    if(answer.empty()) {
        answer.push_back(-1);
    } else{
        sort(answer.begin(), answer.end());
    }

    return answer;
}