#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) 
{
    vector<vector<int>> answer(n, vector<int>(n,0));
    
    int rowMax = n-1;
    int colMax = n-1;
    int rowMin = 0;
    int colMin = 0;
    
    int i = 1;
    while(i <= n * n)
    {
        for(int c=colMin; c<=colMax; c++)
        {
            answer[rowMin][c] = i;
            i++;
        }
        rowMin++;
        for(int r=rowMin; r<=rowMax; r++)
        {
            answer[r][colMax] = i;
            i++;
        }
        colMax--;
        for(int c=colMax; c>=colMin; c--)
        {
            answer[rowMax][c] = i;
            i++;
        }
        rowMax--;
        for(int r=rowMax; r>=rowMin; r--)
        {
            answer[r][colMin] = i;
            i++;
        }
        colMin++;
    }
    return answer;
}