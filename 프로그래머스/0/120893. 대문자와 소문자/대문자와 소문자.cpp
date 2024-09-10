#include <string>
#include <vector>

using namespace std;

string solution(string my_string) 
{
    for(char &c : my_string)
    {
        if(isupper(c))
        {
            c = tolower(c);
        }
        else
        {
            c = toupper(c);
        }
    }
    return my_string;
}