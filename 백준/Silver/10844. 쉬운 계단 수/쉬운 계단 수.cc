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

// 백준문제 - 쉬운 계단 수 [10844]

/* 문제 [DP]
45656이란 수를 보자.
이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

/* 입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

/* 출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

/* 제한
*/

int N;
long long dp[101][10] = {0};

const int MOD = 1000000000;

int StairNum(int N)
{
     for (int i = 1; i <= 9; i++) 
     {
        dp[1][i] = 1;
    }
    
    // DP 테이블 채우기
    for (int length = 2; length <= N; length++) 
    {
        for (int digit = 0; digit <= 9; digit++) 
        {
            if (digit > 0) 
            {
                dp[length][digit] += dp[length - 1][digit - 1];
                dp[length][digit] %= MOD;
            }
            if (digit < 9) 
            {
                dp[length][digit] += dp[length - 1][digit + 1];
                dp[length][digit] %= MOD;
            }
        }
    }
    
    // 길이 N인 계단 수의 총합 구하기
    long long result = 0;
    for (int i = 0; i <= 9; i++) 
    {
        result += dp[N][i];
        result %= MOD;
    }

    return result;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    cout << StairNum(N);
    
    return 0;
}
