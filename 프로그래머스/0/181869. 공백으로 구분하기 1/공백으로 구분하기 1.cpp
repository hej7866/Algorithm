#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) 
{
    vector<string> v;
    string tmp = "";
    for(char c : my_string)
    {
        if(c != ' ')
        {
            tmp += c;
        }
        else if(c == ' ')
        {
            v.push_back(tmp);
            tmp = "";
        }
        
    }
    
    if(!tmp.empty())
    {
        v.push_back(tmp);
    }
    return v;
}