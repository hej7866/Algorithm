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

using namespace std;


/* 문제 [재귀]
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

/* 입력
첫째 줄에 정수 N(0 ≤ N ≤ 20)이 주어진다.

/* 출력
첫째 줄에 N!을 출력한다.


/* 제한
*/


long factorial(int N)
{
    if (N == 0 || N == 1)  // 0!과 1!은 1로 정의됩니다.
    {
        return 1;
    }
    return N * factorial(N - 1);  // 재귀적으로 팩토리얼 계산
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    cout << factorial(N);
    return 0;
}