#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string before, string after) 
{
    int answer = 1;
    for(char &c : before)
    {
        size_t pos = after.find(c);
        if(pos != string::npos)
        {
            after.replace(pos, 1, "#");
        }
    }
    cout << after;
    for(char &c : after)
    {
        if(c != '#')
        {
            answer = 0;
        }
    }
    return answer;
}