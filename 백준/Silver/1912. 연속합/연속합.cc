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
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.
예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

/* 입력
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

/* 출력
첫째 줄에 답을 출력한다.

/* 제한
*/



int sumDP(vector<int>& vec) 
{
    int max_sum = vec[0];
    int current_sum = vec[0];

    for (int i = 1; i < vec.size(); i++) 
    {
        // 현재 요소 하나만 시작하는 경우와 이전 합에 현재 요소를 더하는 경우 중 큰 값을 선택
        current_sum = max(vec[i], current_sum + vec[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> vec[i];
    }
    cout << sumDP(vec) << endl;

    return 0;
}
