#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) 
{
    string target = "ad";
    vector<string> ans;
    for(string s : strArr)
    {
        if(s.find(target) == string::npos)
        {
            ans.push_back(s);
        }
    }
    return ans;
}