#include <string>
#include <vector>

using namespace std;

string solution(string myString)
{
    for(char &ch : myString)
    {
        if(ch < 'l')
        {
            ch = 'l';
        }
    }
    return myString;
}