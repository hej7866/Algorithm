#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    auto min_it = min_element(arr.begin(), arr.end());
    arr.erase(min_it);
    
    if(arr.empty())
    {
        arr.push_back(-1);
    }
    return arr;
}