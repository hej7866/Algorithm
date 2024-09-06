#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int n)
{
    int start = my_string.length() - n;
    
    string str = my_string.substr(start,n);
    return str;

}