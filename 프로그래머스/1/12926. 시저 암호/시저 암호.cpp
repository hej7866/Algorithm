#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) 
{
    for(char &c : s)
    {
        if(c != ' ')
        {
            if (c >= 97 && c <= 122) 
            {
                if (c + n > 122) 
                {
                    c = c + n - 26;
                } 
                else 
                {
                    c = c + n;
                }
            }
            else if(c >= 65 && c <= 90)
            {
                if (c + n > 90) 
                {
                    c = c + n - 26;
                } 
                else 
                {
                    c = c + n;
                }
            }
        }
    }
    return s;
}