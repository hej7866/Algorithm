#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int i=1;
    int c = 1;
    while(true)
    {
        if(i == n)
        {
            break;
        }
        else if(i > n)
        {
            c--;
            break;
        }
        else
        { 
            c++;
            i *= c;
        }
    }
    return c;
}