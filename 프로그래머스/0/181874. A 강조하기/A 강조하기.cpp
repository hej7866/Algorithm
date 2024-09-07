#include <string>
#include <vector>

using namespace std;

string solution(string myString) 
{
    for(char &ch : myString)
    {
        if(ch == 'a')
        {
            char upperch = toupper(ch);
            ch = upperch;
        }
        else if(ch != 'A' && isupper(ch))
        {
            char lowerch = tolower(ch);
            ch = lowerch;
        }
    }
    return myString;
}