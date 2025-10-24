#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list)
{
    int size = num_list.size();
    int ans;
    if(size >= 11)
    {
        ans = 0;
        for(int n : num_list)
        {
           ans += n; 
        }
    }
    else
    {
        ans = 1;
        for(int n : num_list)
        {
           ans *= n; 
        }
    }
    return ans;
}