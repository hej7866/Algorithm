#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s) 
{
    string tmp = "";
    sort(s.begin(), s.end());
    vector<string> tmp_vec;
    for(int i=0; i<s.length(); i++)
    {
        if(i>=1 && s[i] != s[i-1])
        {
            if(tmp.length() == 1)
            {
                tmp_vec.push_back(tmp);
                tmp = "";
            }
            else if(tmp.length() > 1)
            {
                tmp = "";
            }
        }
        tmp += s[i];
    }
    if(s[s.length()-1] != s[s.length()-2])
    {     
        tmp_vec.push_back(tmp);
    }
    
    string result = "";
    for(string &s : tmp_vec)
    {
        cout << s << " ";
        result += s;
    }
    return result;
}