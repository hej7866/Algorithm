#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n) 
{
    string result = "";
    for(char &c : my_string)
    {
        for(int i=0; i<n; i++)
        {
            result += c;
        }
    }
    return result;
}