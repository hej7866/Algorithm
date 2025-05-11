#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) 
{
    vector<string> ans;
    string tmp; 
    for(char c : my_string)
    {
        if(c == ' ')
        {
            ans.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp += c;
        }
        
    }
    ans.push_back(tmp);
    return ans;
}