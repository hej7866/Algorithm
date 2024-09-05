#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) 
{
    string str = "";
    for(int i=0; i<str1.size(); i++)
    {
        str += str1[i];
        str += str2[i];
    }
    return str;
}