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

/* 문제 [백트래킹]
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.

/* 입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 7)

/* 출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
수열은 사전 순으로 증가하는 순서로 출력해야 한다.

/* 제한
*/


// 1 < n < m < 7
int arr[7]; // {1,2,3,4,5,6,7}
vector<int> vec;
int n,m;


void Print()
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << "\n";
}

void BT(int length)
{
	if (length == m)
	{
		Print();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		vec.push_back(arr[i]);
        BT(length + 1);
        vec.pop_back();
	}
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        arr[i] = i + 1;
    }
    BT(0);
    return 0;
}
