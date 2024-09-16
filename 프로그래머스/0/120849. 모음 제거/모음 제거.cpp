#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) 
{
    vector<char> vec = {'a','e','i','o','u'};
    string result = "";
    for(char &c : my_string)
    {
        if(find(vec.begin(), vec.end(), c) == vec.end())
        {
            result += c;
        }
    }
    return result;
}