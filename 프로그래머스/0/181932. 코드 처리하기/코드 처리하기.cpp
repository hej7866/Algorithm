#include <string>
#include <vector>

using namespace std;

string solution(string code) 
{
    int mode = 0;
    string ret = "";
    for(int i=0; i<code.length(); i++)
    {
        if(mode == 0)
        {
            if(code[i] != '1')
            {
                if(i%2 == 0)
                {
                    ret += code[i];
                }
            }
            else if(code[i] == '1')
            {
                mode = 1;
            }          
        }
        else if(mode == 1)
        {
            if(code[i] != '1')
            {
                if(i%2 == 1)
                {
                    ret += code[i];
                }
            }
            else if(code[i] == '1')
            {
                mode = 0;
            }          
        }
    }
    if(ret.empty())
    {
        ret = "EMPTY";
    }
    return ret;
}