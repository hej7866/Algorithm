#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) 
{
    if(search(str2.begin(), str2.end(), str1.begin(), str1.end()) != str2.end())
    {
        return 1;
    }
    return 0;
}