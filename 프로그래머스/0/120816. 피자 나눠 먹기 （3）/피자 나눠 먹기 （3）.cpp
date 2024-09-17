#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) 
{
    int sc = 0;
    int count = 1;
    while(true)
    {
        sc = slice * count;
        if(sc >= n)
        {
            break;
        }
        else
        {
            count++;
        }
    }
    return count;
}