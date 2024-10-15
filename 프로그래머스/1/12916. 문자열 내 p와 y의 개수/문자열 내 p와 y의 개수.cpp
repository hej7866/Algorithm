#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int pc = 0;
    int yc = 0;
    for(char &ch : s)
    {
        if(ch == 'p' || ch == 'P')
        {
            pc++;
        }
        else if(ch == 'y' || ch == 'Y')
        {
            yc++;
        }
    }
    
    return (pc == yc);
}