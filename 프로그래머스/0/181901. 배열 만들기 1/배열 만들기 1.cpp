#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int k)
{
    vector<int> v;
    for(int i = 1; i<=n; i++)
    {
        if(i%k == 0)
        {
            v.push_back(i);
        }
    }
    return v;
}