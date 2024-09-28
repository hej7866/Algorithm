#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int ans = 0;
    for(int x = n - 1; x >= 2; x--)
    {
        if(n%x == 1)
        {
            ans = x;
        }
    }
    return ans;
}