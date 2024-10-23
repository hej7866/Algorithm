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
춘향이는 편의점 카운터에서 일한다.

손님이 2원짜리와 5원짜리로만 거스름돈을 달라고 한다. 2원짜리 동전과 5원짜리 동전은 무한정 많이 가지고 있다. 
동전의 개수가 최소가 되도록 거슬러 주어야 한다. 거스름돈이 n인 경우, 최소 동전의 개수가 몇 개인지 알려주는 프로그램을 작성하시오.

예를 들어, 거스름돈이 15원이면 5원짜리 3개를, 거스름돈이 14원이면 5원짜리 2개와 2원짜리 2개로 총 4개를, 
거스름돈이 13원이면 5원짜리 1개와 2원짜리 4개로 총 5개를 주어야 동전의 개수가 최소가 된다.

/* 입력
첫째 줄에 거스름돈 액수 n(1 ≤ n ≤ 100,000)이 주어진다.

/* 출력
거스름돈 동전의 최소 개수를 출력한다. 만약 거슬러 줄 수 없으면 -1을 출력한다.

/* 제한
*/

vector<int> dp;

int minCoin(int money)
{
    if(money == 0) return 0;
    if(money < 0) return -1;

    if(dp[money] != -1)
    {
        return dp[money];
    }

    int result2 = minCoin(money-2); // 2원을 거슬러 주었을 때
    int result5 = minCoin(money-5); // 5원을 거슬러 주었을 때

    if(result2 == -1 && result5 == -1)
    {
        dp[money] = -1; 
    }
    else if(result2 == -1)
    {
        dp[money] = result5 + 1;
    }
    else if(result5 == -1)
    {
        dp[money] = result2 + 1;
    }
    else
    {
        dp[money] = min(result2, result5) + 1;
    }

    return dp[money];
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp.assign(n+1, -1);

    cout << minCoin(n) << "\n";
    return 0;
}