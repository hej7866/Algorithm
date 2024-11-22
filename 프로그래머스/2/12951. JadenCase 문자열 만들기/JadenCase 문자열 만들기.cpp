#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s) 
{
    vector<int> spaceIdx;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            spaceIdx.push_back(i);
        }
        else
        {
            if(isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    for(int idx : spaceIdx)
    {
        if(islower(s[idx + 1]))
        {
            s[idx + 1] = toupper(s[idx + 1]);
        }
    }
    if(islower(s[0])) s[0] = toupper(s[0]);
    return s;
}