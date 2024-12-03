#include <vector>

using namespace std;

void hanoi(int n, int from, int to, int via, vector<vector<int>> &result) 
{
    if (n == 1) 
    {
        result.push_back({from, to});
    } 
    else 
    {
        hanoi(n - 1, from, via, to, result);
        result.push_back({from, to});
        hanoi(n - 1, via, to, from, result);
    }
}

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> result;
    hanoi(n, 1, 3, 2, result);
    return result;
}