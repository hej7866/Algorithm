#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) 
{
    string strN = to_string(n);
    vector<int> vec;
    while(!strN.empty())
    {
        vec.push_back(strN.back() - '0');
        strN.pop_back();
    }
    
    return vec;
}