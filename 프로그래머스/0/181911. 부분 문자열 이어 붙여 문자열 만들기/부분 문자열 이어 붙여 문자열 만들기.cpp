#include <string>
#include <vector>

using namespace std;

string solution(vector<string> my_strings, vector<vector<int>> parts) 
{
    string sumStr = "";
    for(int i=0; i<my_strings.size(); i++)
    {
        int start = parts[i][0];
        int len = parts[i][1] - parts[i][0] + 1;
        sumStr += my_strings[i].substr(start,len);
    }
    return sumStr;
}