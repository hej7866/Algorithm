#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string myString, string pat) 
{
    size_t pos = myString.find(pat);
    int idx = 0;
    while (pos != string::npos) {
        if(myString.find(pat))
        {
            idx = (int)pos;
        }
        pos = myString.find(pat, pos + 1); // 다음 위치부터 다시 검색
    }
    
    int size = pat.size();
    cout << idx << "\n" << size;
    int a = idx + size - 1;
    
    string ans = "";
    for(int i=0; i<=a; i++)
    {
        ans += myString[i];
    }
    
    return ans;
}