#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) 
{
    return (search(str1.begin(),str1.end(), str2.begin(),str2.end()) != str1.end()) ? 1 : 2;
}