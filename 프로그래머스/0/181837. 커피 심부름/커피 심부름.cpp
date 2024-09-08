#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> order) 
{
    string am = "americano";
    string cf = "cafelatte";
    string at = "anything";
    
    int americanoCount = 0;
    int cafelatteCount = 0;
    for(string &s : order)
    {
        if(search(s.begin(), s.end(), am.begin(), am.end()) != s.end() ||
           search(s.begin(), s.end(), at.begin(), at.end()) != s.end())
        {
            americanoCount++;
        }
        else if(search(s.begin(), s.end(), cf.begin(), cf.end()) != s.end())
        {
            cafelatteCount++;
        }
    }
    return americanoCount * 4500 + cafelatteCount * 5000;
}