#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int count = 0;
    int i = 1;
    while(i <= n)
    {
        if(n%i == 0)
        {
            count++;
        }
        i++;
    }
    return count;
}