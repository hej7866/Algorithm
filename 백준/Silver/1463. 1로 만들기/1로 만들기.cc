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

// 백준문제 - 1로 만들기 [1463]

/* 문제 [DP]
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

/* 입력
첫째 줄에 1보다 크거나 같고, 10^6보다 작거나 같은 정수 N이 주어진다.

/* 출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

/* 제한
*/

int N;
int cnt = 0;

int MakeOne(int dp[], int N)
{
    dp[1] = 0;  // 1을 1로 만드는 데 필요한 연산 횟수는 0

    for (int i = 2; i <= N; ++i) 
    {
        dp[i] = dp[i - 1] + 1;  // 기본적으로 1을 빼는 연산을 수행

        if (i % 2 == 0) 
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);  // 2로 나누어 떨어지면 최소값을 업데이트
        }
        if (i % 3 == 0)
        { 
            dp[i] = min(dp[i], dp[i / 3] + 1);  // 3으로 나누어 떨어지면 최소값을 업데이트
        }
    }
    return dp[N];
}   

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int dp[N + 1];
    cout << MakeOne(dp, N);
    
    return 0;
}