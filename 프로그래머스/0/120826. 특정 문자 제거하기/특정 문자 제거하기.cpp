#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) 
{
    while(my_string.find(letter[0]) != string::npos)
    {
        int pos = my_string.find(letter[0]);
        my_string.erase(pos,1);
    }
    return my_string;
}