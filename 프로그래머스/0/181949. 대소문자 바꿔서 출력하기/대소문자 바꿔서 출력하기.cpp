#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    string str;
    cin >> str;
    
    for (char &c : str) // 모든 문자를 순회
    {
        if (isupper(c)) // 문자가 대문자인 경우
        {
            c = tolower(c); // 소문자로 변환
        }
        else if (islower(c)) // 문자가 소문자인 경우
        {
            c = toupper(c); // 대문자로 변환
        }
    }
    cout << str;
    return 0;
}