#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void sol(int num, int i)
{
    int sum = 0;
    for(int j = i; j<=num; j++)
    {
        sum += j;
        if(sum == num) cnt++;
        else if(sum > num)
        {
            return;
        }
    }
}

int solution(int n) 
{
    int num = n;
    for(int i=1; i<=n; i++)
    {
        sol(num, i);
    }
    return cnt;
}