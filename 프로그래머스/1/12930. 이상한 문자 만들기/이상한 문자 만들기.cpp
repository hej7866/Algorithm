#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    int idx = 0;
    for(char &c : s)
    {
        if(c == ' ')
        {
            idx = 0;
        }
        else if(c != ' ')
        {
            if(idx%2 == 0)
            {
                c = toupper(c);
            }
            else if(idx%2 == 1)
            {
                c = tolower(c);
            }
            idx++;
        }
    }
    return s;
}