#include <string>
#include <vector>

using namespace std;

string solution(string n_str) 
{
    while(true)
    {
        if(n_str[0] == '0')
        {
            n_str.erase(0,1);
        }
        
        if(n_str[0] != '0') { break; }
    }
    return n_str;
}