#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int k) 
{
    string str_multiply = "";
    for(int i=0; i<k; i++)
    {
        str_multiply += my_string;
    }
    return str_multiply;
}