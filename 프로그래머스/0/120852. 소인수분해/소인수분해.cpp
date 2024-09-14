#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n) 
{
    vector<int> vec;
    int i = 2;
    while(i<=n)
    {
        while(n%i == 0)
        {
            if(find(vec.begin(), vec.end(), i) == vec.end())
            {  
                vec.push_back(i);
            }
            n /= i;
        }
        i++;
    }
    return vec;
}