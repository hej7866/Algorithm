#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) 
{
    string strN = to_string(n);
    
    vector<int> vec;
    for(char &c : strN)
    {
        vec.push_back(c-'0');
    }
    sort(vec.begin(), vec.end(), greater<int>());
    
    string result = "";
    for(int &i : vec)
    {
        result += to_string(i);     
    }
    
    return stoll(result);
}