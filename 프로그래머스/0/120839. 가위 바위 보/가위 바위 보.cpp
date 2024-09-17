#include <string>
#include <vector>

using namespace std;

string solution(string rsp) 
{
    string result = "";
    
    for(char &c : rsp)
    {
        if(c == '2')
        {
            result += '0';
        }
        else if(c == '0')
        {
            result += '5';
        }
        else
        {
            result += '2';
        }
    }
    return result;
}