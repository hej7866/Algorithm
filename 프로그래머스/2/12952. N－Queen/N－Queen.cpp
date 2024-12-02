#include <string>
#include <vector>

using namespace std;

int total;
int max_col;

void dfs(int cols, int diag1, int diag2) 
{
    if (cols == max_col) 
    {
        total++;
        return;
    }
    int available_positions = max_col & ~(cols | diag1 | diag2);
    while (available_positions) 
    {
        int position = available_positions & -available_positions; // 가장 오른쪽 1비트 추출
        available_positions -= position;
        dfs(cols | position, (diag1 | position) << 1, (diag2 | position) >> 1);
    }
}

int solution(int n) 
{
    total = 0;
    max_col = (1 << n) - 1;
    dfs(0, 0, 0);
    return total;
}
