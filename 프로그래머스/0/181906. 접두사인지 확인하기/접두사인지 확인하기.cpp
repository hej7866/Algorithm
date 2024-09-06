#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_prefix) 
{
    vector<string> prefixVec;
    for(int i=0; i<my_string.length(); i++)
    {
        int len = my_string.length() - i;
        prefixVec.push_back(my_string.substr(0,len));
    }
    return (find(prefixVec.begin(), prefixVec.end(), is_prefix) != prefixVec.end()) ? 1 : 0;
}