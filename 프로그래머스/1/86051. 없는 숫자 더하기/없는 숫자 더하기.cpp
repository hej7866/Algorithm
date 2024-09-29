#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int ans = 0;
    for(int i=0; i<=9; i++)
    {
        bool isBool = false;
        for(int &num : numbers)
        {
            if(i == num)
            {
                isBool = true;
            }
        }
        if(!isBool)
        {
            ans += i;
        }
    }
    return ans;
}