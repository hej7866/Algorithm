#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) 
{
    vector<string> v;
    string s = "";
    int n = -1;
    
    for(int i=0; i<my_string.size(); i++)
    {
        n = i + 1;
        s.push_back(my_string[i]);
        if(n%m == 0)
        {
            v.push_back(s);
            s = "";
        }
    }
    
    string ans;
    for(string s : v)
    {
        ans += s[c-1];
    }
    return ans;
}