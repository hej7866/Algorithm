#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) 
{
    int i = 0;
    vector<int> vec;
    while(i<=n)
    {
        if(i%2 == 1)
        {
            vec.push_back(i);
        }
        i++;
    }
    return vec;
}