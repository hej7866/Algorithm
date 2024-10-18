#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string ans = "";
    if(s.length() % 2 == 1)
    {
       ans = s[(s.length() - 1) / 2];
    }
    else
    {
        ans += s[(s.length()) / 2 - 1];
        ans += s[(s.length()) / 2];
    }
    return ans;
}