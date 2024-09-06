#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string myString, string pat) 
{
    // 소문자로 변환
    transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
    transform(pat.begin(), pat.end(), pat.begin(), ::tolower);
    
    int answer = 0;
    // search는 find와 달리 서브스트링(하위시퀀스)를 찾는데 용이하다.
    // 첫 번째와 두 번째 매개변수: 검색 범위의 시작과 끝. 세 번째와 네 번째 매개변수: 찾고자 하는 서브스트링의 시작과 끝.
    if (search(myString.begin(), myString.end(), pat.begin(), pat.end()) != myString.end())
    {
        answer = 1;
    }
    return answer;
}