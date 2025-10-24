#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) 
{
    size_t pos = myString.find(pat);
    int count = 0;
    while (pos != string::npos) 
    {
        count++;
        pos = myString.find(pat, pos + 1); // 다음 위치부터 다시 검색
    }
    return count;
}