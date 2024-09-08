#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer(n, vector<int>(n, 0));
    for(int i=0; i<answer.size(); i++)
    {
        answer[i][i] = 1;
    }
    return answer;
}