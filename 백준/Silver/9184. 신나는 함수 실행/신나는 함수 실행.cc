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


/* 문제 [DP]
재귀 호출만 생각하면 신이 난다! 아닌가요?
다음과 같은 재귀함수 w(a, b, c)가 있다.

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

위의 함수를 구현하는 것은 매우 쉽다. 하지만, 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다. (예를 들면, a=15, b=15, c=15)
a, b, c가 주어졌을 때, w(a, b, c)를 출력하는 프로그램을 작성하시오.


/* 입력
입력은 세 정수 a, b, c로 이루어져 있으며, 한 줄에 하나씩 주어진다. 입력의 마지막은 -1 -1 -1로 나타내며, 세 정수가 모두 -1인 경우는 입력의 마지막을 제외하면 없다.

/* 출력
입력으로 주어진 각각의 a, b, c에 대해서, w(a, b, c)를 출력한다.

/* 제한
-50 ≤ a, b, c ≤ 50
*/

int a, b, c;
int dp[21][21][21];

int w(int a, int b, int c) // 재귀
{
    if(a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20)
    {
        return w(20,20,20);
    }
    else if(a < b && b < c)
    {
        return w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    }
    else
    {
        return w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    }
}

int wDP(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) 
    {
        return 1;
    }

    // 배열 범위를 벗어난 값 처리
    if (a > 20 || b > 20 || c > 20) 
    {
        return wDP(20, 20, 20);
    }

    // 이미 계산된 값이 있으면 바로 반환 (이 작업 없으면 시간 초과 남)
    if (dp[a][b][c] != 0) 
    {
        return dp[a][b][c];
    }

    // 값이 없을 경우 계산하여 배열에 저장
    if (a < b && b < c) 
    {
        dp[a][b][c] = wDP(a, b, c-1) + wDP(a, b-1, c-1) - wDP(a, b-1, c);
    } 
    else 
    {
        dp[a][b][c] = wDP(a-1, b, c) + wDP(a-1, b-1, c) + wDP(a-1, b, c-1) - wDP(a-1, b-1, c-1);
    }

    return dp[a][b][c]; // 계산된 값을 반환
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> a >> b >> c)
    {
        if(a == -1 && b == -1 && c == -1)
        {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << wDP(a,b,c) << "\n";
    }


    return 0;
}