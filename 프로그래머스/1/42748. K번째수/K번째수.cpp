#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> result;
    for(auto &v : commands)
    {
        vector<int> vec;
        for(int i=v[0] - 1; i < v[1]; i++)
        {
            vec.push_back(array[i]);
        }
        sort(vec.begin(), vec.end());
        result.push_back(vec[v[2] - 1]);
    }
    return result;
}