#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool isBool = true;
    for(char &c : s)
    {
        if(!isdigit(c))
        {
            isBool = false;
            break;
        }
    }
    
    if(s.length() != 4 && s.length() != 6)
    {
        isBool = false;
    }
    
    return isBool;
}