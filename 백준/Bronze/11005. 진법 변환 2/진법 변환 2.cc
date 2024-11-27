#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
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

// 문제 - 일반 수한

/* 문제 - 진법 변환 2 [11005]
10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.
10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

/*
입력
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.

/* 출력
첫째 줄에 10진법 수 N을 B진법으로 출력한다.


/* 제한
*/

string toBase(int N, int B) 
{
    string result = "";
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (N > 0) 
    {
        int remainder = N % B;      // 나머지 계산
        result += digits[remainder]; // 나머지에 해당하는 문자 추가
        N /= B;                    // 몫 갱신
    }

    reverse(result.begin(), result.end()); // 결과를 뒤집어 올바른 순서로 정렬
    return result;
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, B;
    cin >> N >> B;

    cout << toBase(N, B) << endl;
    return 0;
}