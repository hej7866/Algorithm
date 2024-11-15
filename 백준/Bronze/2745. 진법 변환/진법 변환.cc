#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

// 백준문제 - 진법 변환 [2745]

/* 문제 [일반 수학]
B진법 수 N이 주어진다. 이 수를 10진법으로 바꿔 출력하는 프로그램을 작성하시오.
10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

/*
입력
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36)
B진법 수 N을 10진법으로 바꾸면, 항상 10억보다 작거나 같다.

/* 출력
첫째 줄에 B진법 수 N을 10진법으로 출력한다.

/* 제한
*/

int main() 
{
    string N;
    int B;
    
    // 입력 받기
    cin >> N >> B;
    
    int result = 0;
    int length = N.length();
    
    // 문자열의 각 자리 처리
    for (int i = 0; i < length; ++i) 
    {
        char c = N[i];
        int value;
        
        // 문자가 숫자인 경우
        if (c >= '0' && c <= '9') 
        {
            value = c - '0';
        }
        // 문자가 알파벳(A-Z)인 경우
        else if (c >= 'A' && c <= 'Z')
        {
            value = c - 'A' + 10;
        }
        
        // 진법 변환 계산: 자릿값 * (진법^자리 위치)
        result += value * pow(B, length - 1 - i);
    }
    
    // 결과 출력
    cout << result << endl;
    return 0;
}