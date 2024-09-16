#include <string>
#include <vector>

using namespace std;

int result = 0;
int solution(int n) 
{
    for(int i=1; i<=n; i++)
    {
        int c = 1;
        int count = 0;
        while(c <= i)
        {
            if(i%c == 0)
            {
                count++;
            }
            c++;
        }
        if(count >= 3)
        {
            result++;
        }
    }
    return result;
}