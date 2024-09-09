#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) 
{
    
    vector<string> possibleVec = { "aya", "ye", "woo", "ma"};
    for(string &b : babbling) // babbling의 원소를 b에 담는다
    {
        for(string &v : possibleVec)// possible의 원소를 b에 담는다
        {
            size_t pos = b.find(v); // b에 v가 등장하는 위치를 담는다.
            if(pos != string::npos) // 만약 위치가 존재한다면
            {
                b.replace(pos, v.size(), "#"); // b의 pos번째 인덱스부터 v의 길이만큼을 #이라는 문자열로 바꾼다.
            }
        }
        cout << b << " ";
    }
    
    int count = 0;
    for(string &b : babbling) // babbling의 원소를 b에담는다
    {
        bool isSharp = true; // b가 #으로만 구성되어있는지 확인하는 bool값
        // b가 #으로만 구성되어있는지 확인하는 로직
        for(int i=0; i<b.length(); i++)
        {           
            if(b[i] != '#')
            {
                isSharp = false;
                break;
            }
        }
        if(isSharp)
        {
            count++;
        }
    }
    return count;
}