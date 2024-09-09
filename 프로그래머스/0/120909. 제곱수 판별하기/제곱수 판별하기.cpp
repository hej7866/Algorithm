#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int i = 1;
    bool isbool = false;
    while(n >= i * i)
    {
        if(n == i * i)
        {
            isbool = true;
            break;
        }
        i++;
    }
    return isbool ? 1 : 2;
}