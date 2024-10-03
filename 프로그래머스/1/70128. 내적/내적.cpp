#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) 
{
    int n = a.size();
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans += a[i] * b[i];
    }
    return ans;
}