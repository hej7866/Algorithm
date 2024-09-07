#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) 
{
    int count = 0;
    for(int i=0; i<=myString.size() - pat.size(); i++)
    {
        if(myString.compare(i,pat.size(), pat) == 0) // compare(시작위치, 검사할 길이, 검사할 문자열) 있다면 0 반환 
        {
            count++;
        }    
    }
    return count;
}