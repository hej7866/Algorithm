#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) 
{
    int count = 0;
    size_t pos = myString.find(pat);
    while (pos != string::npos) 
    {
        count++;
        pos = myString.find(pat, pos + 1); // 겹쳐서 나오는 것도 찾으려면 +1로 이동
    }
    return count;
}