#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string myString, string pat) 
{
    for(char &ch : myString)
    {
        if(ch == 'A')
        {
            ch = 'B';
        }
        else if(ch == 'B')
        {
            ch = 'A';
        }
    }
    // 단순하게 search는 문자열이 포함되어있는가?? compare는 특정문자열이 등장하는 index를 체크하면서 포함까지체크
    if(search(myString.begin(), myString.end(), pat.begin(), pat.end()) != myString.end())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}