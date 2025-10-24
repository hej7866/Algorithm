#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp)
{
    for(char &c : my_string)
    {
        string tmp = "";
        tmp.push_back(c);
        
        if(tmp == alp)
        {
            c = c - 32;
        }
    }
    return my_string;

    
}