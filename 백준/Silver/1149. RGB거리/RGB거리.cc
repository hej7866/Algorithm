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

// 백준문제 - RGB거리 [1149]

/* 문제 [DP]
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.
1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

/* 입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

/* 출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.

/* 제한
*/

int N;
vector<vector<int>> RGBvec;

int RGB() 
{
    // DP 배열 초기화: 이전 집을 빨강, 초록, 파랑으로 칠할 때의 최소 비용 누적
    for (int i = 1; i < N; i++) {
        RGBvec[i][0] += min(RGBvec[i - 1][1], RGBvec[i - 1][2]); // 빨강으로 칠할 때 이전 집은 초록 또는 파랑
        RGBvec[i][1] += min(RGBvec[i - 1][0], RGBvec[i - 1][2]); // 초록으로 칠할 때 이전 집은 빨강 또는 파랑
        RGBvec[i][2] += min(RGBvec[i - 1][0], RGBvec[i - 1][1]); // 파랑으로 칠할 때 이전 집은 빨강 또는 초록
    }

    // 마지막 집을 각각 빨강, 초록, 파랑으로 칠할 때의 최소 비용 중 최솟값
    return min({RGBvec[N - 1][0], RGBvec[N - 1][1], RGBvec[N - 1][2]});
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    RGBvec.assign(N, vector<int>(3));

    for (int i = 0; i < N; i++) {
        cin >> RGBvec[i][0] >> RGBvec[i][1] >> RGBvec[i][2];
    }

    cout << RGB() << "\n";
    return 0;
}