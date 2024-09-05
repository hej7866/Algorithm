#include <string>
#include <vector>

using namespace std;

string solution(vector<string> arr) 
{
    string result = "";
    for(string &c : arr)
    { 
        result += c; 
    }
    return result;
}