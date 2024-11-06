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

// 백준문제 - 가장 긴 바이토닉 부분 수열 [11054]

/* 문제 [DP]
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만, {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.
수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

/* 입력
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

/* 출력
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

/* 제한
*/

int N;

void Bitonic(const vector<int>& vec)
{
    vector<int> incr(N, 1);  // 증가 부분 수열 길이
    vector<int> decr(N, 1);  // 감소 부분 수열 길이
    
    // 증가하는 부분 수열 계산
    for(int i = 1; i < N; i++) 
    {
        for(int j = 0; j < i; j++) 
        {
            if(vec[i] > vec[j]) 
            {
                incr[i] = max(incr[i], incr[j] + 1);
            }
        }
    }

    // 감소하는 부분 수열 계산
    for(int i = N - 2; i >= 0; i--) 
    {
        for(int j = N - 1; j > i; j--) 
        {
            if(vec[i] > vec[j]) 
            {
                decr[i] = max(decr[i], decr[j] + 1);
            }
        }
    }

    // 가장 긴 바이토닉 부분 수열의 길이 계산
    int max_length = 0;
    for(int i = 0; i < N; i++) 
    {
        max_length = max(max_length, incr[i] + decr[i] - 1);
    }

    cout << max_length << endl;
}

int main() 
{
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) 
    {
        cin >> vec[i];
    }
    Bitonic(vec);
    return 0;
}