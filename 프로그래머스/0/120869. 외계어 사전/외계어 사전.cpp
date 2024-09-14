#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> spell, vector<string> dic)
{
    int answer = 2;
    vector<string> vec;
    for(string &str : dic)
    {
        bool isBool = false;
        for(string &s : spell)
        {
            if(str.find(s) == string::npos)
            {   
                isBool = true;
            }
        }
        if(isBool)
        {
            isBool = false;
            continue;
        }
        vec.push_back(str);
    }
    
    for(string &str : vec)
    {
        for(string &s : spell)
        {
            while(str.find(s) != string::npos)
            {   
                size_t pos = str.find(s);
                str.erase(pos,1);
            }
        }
        cout << str << " ";
        if(str == "")
        {
            answer = 1;
            break;
        }
    }
    return answer;
}