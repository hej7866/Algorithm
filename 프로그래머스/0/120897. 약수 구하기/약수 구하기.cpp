#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) 
{
    vector<int> divisor;
    for(int i=1; i<=n ; i++)
    {
        if(n%i == 0)
        {
            divisor.push_back(i);
        }
    }
    return divisor;
}