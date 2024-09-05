#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) 
{
    int num_sum = 0;
    for(int i=0; i<included.size(); i++)
    {
        if(included[i])
        {
            num_sum += a;
        }
        a += d;
    }
    return num_sum;
}