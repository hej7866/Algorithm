#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(int age) 
{
    string result = "";
    map<char, char> ageMap = 
    {
        {'0','a'},{'1','b'},{'2','c'},{'3','d'},{'4','e'},
        {'5','f'},{'6','g'},{'7','h'},{'8','i'},{'9','j'}
    };
    for(char &c : to_string(age))
    {
        result += ageMap[c];
    }
    return result;
}