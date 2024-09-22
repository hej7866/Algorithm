#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) 
{
    vector<string> vec;
    
    int idx = 0;
    while(true)
    {
        char ch = s[idx];
        
        int eNum = 0;
        int dNum = 0;
        string tmp = "";
        bool isBool = false;
        for(int i=idx; i<s.length(); i++)
        {
            if(ch == s[i]) { eNum++; }
            else if(ch != s[i]) { dNum++; }
            
            tmp += s[i];
            if(eNum == dNum)
            {
                vec.push_back(tmp);
                tmp = "";
                if(i+1 < s.length()) { idx = i+1; }
                else if(i+1 == s.length()) { break; }
                isBool = true;
                break;
            }
        }
        if(!isBool)
        {
            if(!tmp.empty())
            {
                vec.push_back(tmp);
            }
            break;
        }
    }
    for(string str : vec)
    {
        cout << str << " ";
    }
    return vec.size();
}

// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ참고한 코드ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ //

// #include <string>
// #include <vector>

// using namespace std;

// int solution(string s) {
//     int answer = 0;
//     int xCount = 1;
//     int yCount = 0;
//     char x = s[0];

//     for (int i = 1; i < s.size(); i++) {
//         if (s[i] == x) {
//             xCount++;
//         } else {
//             yCount++;
//         }

//         if (xCount == yCount) {
//             xCount = 0;
//             yCount = 0;
//             answer++;
//             x = s[i + 1];
//         }
//     }

//     if (xCount > 0) answer++;

//     return answer;
// }