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

// 문제 - 집합과 맵

/* 문제 - 대칭 차집합 [1269]
자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다. 이때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오. 
두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.
예를 들어, A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때,  A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로, 대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.

/*
입력
첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다. 둘째 줄에는 집합 A의 모든 원소가, 셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다. 
각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.

/* 출력
첫째 줄에 대칭 차집합의 원소의 개수를 출력한다. 

/* 제한
*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_set<int> setA, setB;

    // 집합 A 입력
    for (int i = 0; i < N; i++) 
    {
        int a;
        cin >> a;
        setA.insert(a);
    }

    // 집합 B 입력
    for (int i = 0; i < M; i++) 
    {
        int b;
        cin >> b;
        setB.insert(b);
    }

    // 대칭 차집합 계산
    int cnt = 0;
    for (int x : setA) 
    {
        if (setB.find(x) == setB.end()) 
        {
            cnt++;
        }
    }
    for (int x : setB) 
    {
        if (setA.find(x) == setA.end()) 
        {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}