#include <string>
#include <vector>

using namespace std;

string solution(string my_string) 
{
    string result = "";
    for(int i=my_string.size()-1; i>=0; i--)
    {
        result += my_string[i];
    }
    return result;
}