#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) 
{
    int n = common.size() - 1;
    
    if(common[1]-common[0] == common[n] - common[n-1])
    {
        return common[n] + (common[1] - common[0]);
    }
    else
    {
        return common[n] * (common[1]/common[0]);
    }
}