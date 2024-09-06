#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) 
{
    vector<string> answer;
    
    int start = my_string.length() - 1;
    vector<string> strVec;
    int len = 1;
    for(int i=start; i>=0; i--)
    {
        strVec.push_back(my_string.substr(i,len));
        len++;
    }
    sort(strVec.begin(), strVec.end());
    return strVec;
}