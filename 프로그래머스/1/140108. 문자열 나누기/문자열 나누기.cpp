#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) 
{
    // 이 문제의 경우 굳이 vec를 만들필요는 없다
    // 하지만 분해된 문자열을 담은 벡터를 반환하라는 문제가 나올수도 있으니 다음과 같이 해결하였다.
    
    // 분해된 문자열을 담을 벡터
    vector<string> vec;
    
    // 처음 idx를 0으로 초기화
    int idx = 0;
    
    // 조건을 만족하기 전까진 루프를 반복할 것.
    while(true) 
    {
        char x = s[idx]; // x에 s의 idx번째 값을 담는다. 
        
        int eNum = 0; // x와 같은 글자의 수를 담을 변수
        int dNum = 0; // x와 다른 글자의 수를 담을 변수
        string tmp = ""; // 분해된 문자열을 담을 변수
        
        // eNum과 dNum이 같아져서 멈춘것인지 아니면 s의 모든 인덱스를 순환해서 멈춘것인지 확인하는 변수
        bool isBool = false;
        for(int i=idx; i<s.length(); i++) // idx부터 s.length()까지 순환
        {
            if(x == s[i]) { eNum++; } // s[i]가 x와 같다면 eNum++;
            else if(x != s[i]) { dNum++; } // s[i]가 x와 다르다면 dNum++;
            
            tmp += s[i]; // tmp엔 s[i]를 붙혀넣음 (자른 문자열이 되는 것)
            if(eNum == dNum) // 만약 eNum 와 dNum이 같다면 
            {
                vec.push_back(tmp); // tmp,즉 자른 문자열을 vec에 넣고
                tmp = ""; // tmp를 빈 문자열로 초기화
                if(i+1 < s.length()) { idx = i+1; } // 만약 i+1이 s.length()보다 작다면 idx 를 i+1로 초기화
                else if(i+1 == s.length()) { break; } // i+1이 s.length()과 같다면 마지막 글자인것이므로 그냥 break
                isBool = true; // eNum과 dNum이 같아서 멈춘것이므로 true
                break;
            }
        }
        if(!isBool) // eNum과 dNum이 같아서 멈춘것이 아니라면
        {
            if(!tmp.empty()) // tmp가 비어있지 않으면
            {
                vec.push_back(tmp); // vec에 값을 추가
            }
            break; // 이때는 마지막 글자인것이므로 while 반복문을 탈출.
        }
    }
    // 디버그용
        // for(string str : vec)
        // {
        //     cout << str << " ";
        // }
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