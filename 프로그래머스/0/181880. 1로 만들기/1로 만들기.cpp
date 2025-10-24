#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) 
{
    int count = 0;
    for(int n : num_list)
    {
        while(n != 1)
        {
            if(n%2 == 0)
            {
                n /= 2;
                count++;
            }
            else
            {
                n -= 1;
                n /= 2;
                count++;
            }     
        }
    }
    return count;
}