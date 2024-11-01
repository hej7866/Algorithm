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

// 백준문제 - 정수 삼각형 [1932]

/* 문제 [DP]
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

/* 입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

/* 출력
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

/* 제한
*/

int n;

int Solution_1932(vector<vector<int>>& vec, int n) 
{
    // DP 배열 사용해서 vec를 직접 갱신 (Bottom-Up 방식)
    for (int i = n - 2; i >= 0; i--)  // 맨 아래에서 두 번째 줄부터 시작
    {
        for (int j = 0; j <= i; j++)  // 각 줄의 모든 요소에 대해
        {
            vec[i][j] += max(vec[i + 1][j], vec[i + 1][j + 1]);
        }
    }
    
    // vec[0][0]에 최종적으로 최대 합이 저장됨
    cout << vec[0][0] << "\n";
    return vec[0][0];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<vector<int>> vec;
    for(int i = 0; i < n; i++) 
    {
        vector<int> tmp(i + 1);
        for(int j = 0; j <= i; j++) 
        {
            cin >> tmp[j];
        }
        vec.push_back(tmp);
    }

    Solution_1932(vec, n);
    return 0;
}