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

// 문제 - 조합론

/* 문제 - 팩토리얼 [10872]
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

/*
입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)이 주어진다.

/* 출력
첫째 줄에 N!을 출력한다.


/* 제한
*/



int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int ans = 1;
    for(int i=1; i<=N; i++)
    {
        ans *= i;
    }
    cout << ans;

    return 0;
}