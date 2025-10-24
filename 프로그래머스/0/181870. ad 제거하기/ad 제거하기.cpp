#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) 
{
    vector<string> v;
    for(string str : strArr)
    {
        if (str.find("ad") != string::npos)
        {
            continue;
        }
        v.push_back(str);
    }
    return v;
}