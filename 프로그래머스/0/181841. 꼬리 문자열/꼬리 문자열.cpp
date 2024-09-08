#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> str_list, string ex) 
{
    string result = "";
    for(int i=0; i<str_list.size(); i++)
    {
        string str = str_list[i];
        if(search(str.begin(), str.end(), ex.begin(), ex.end()) != str.end())
        {
            continue;
        }
        result += str;
    }
    return result;
}