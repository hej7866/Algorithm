#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) 
{
    vector<int> vec;
    for(int &i : arr)
    {
        if(i%divisor == 0)
        {
            vec.push_back(i);
        }
    }
    sort(vec.begin(), vec.end());
    if(vec.empty())
    {
        vec.push_back(-1);
    }
    return vec;
}