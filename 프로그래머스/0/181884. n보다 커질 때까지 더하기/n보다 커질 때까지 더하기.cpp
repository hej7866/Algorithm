#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) 
{
    int ans = 0;
    for(int i : numbers)
    {
        ans += i;
        if(ans > n) break;
    }
    return ans;
}