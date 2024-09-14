#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots) 
{
    vector<int> x;
    vector<int> y;
    
    for(auto &v : dots)
    {
        x.push_back(v[0]);
        y.push_back(v[1]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int area = (x[2] - x[1]) * (y[2] - y[1]);
    return area;
}