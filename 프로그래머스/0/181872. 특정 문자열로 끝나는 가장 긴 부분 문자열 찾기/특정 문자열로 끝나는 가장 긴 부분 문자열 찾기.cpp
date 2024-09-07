#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) 
{
    while(true)
    {
        // compare 메소드 (시작위치, 검사하고자하는 길이, 검사하고자하는 문자열)
        // 만약 있다면 0을반환
        // 1번예로는 (5, 2, "dE") 가 들어가는거임
        if(myString.compare(myString.size() - pat.size(), pat.size(), pat) == 0)
        {
            break;
        }
        // erase메소드 (시작위치, 삭제하고자하는 문자열의길이)
        myString.erase(myString.size()-1, 1);
    }
    return myString;
}