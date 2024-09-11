#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) 
{
    string temp = "";
    for(char &c : my_string)
    {
        if(find(temp.begin(), temp.end(), c) != temp.end())
        {
            continue;
        }
        else
        {
            temp += c;
        }
    }
    return temp;
}