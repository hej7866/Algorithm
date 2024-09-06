#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int len = num_list.size();
    
    int numSum = 0;
    int numMul = 1;
    if(len >= 11)
    {
        for(int &num : num_list)
        {
            numSum += num;
        }
    }
    else
    {
        for(int &num : num_list)
        {
            numMul *= num;
        }
    }
    return (len >= 11) ? numSum : numMul;
}