#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) 
{
    vector<string> strVec;
    
    for(int i=0; i<my_string.length(); i = i + m)
    {
        strVec.push_back(my_string.substr(i,m));   
    }
    
    string result = "";
    for(int i=0; i<strVec.size(); i++)
    {
        string temp = strVec[i];
        result += temp[c-1];
    }
    return result;
}