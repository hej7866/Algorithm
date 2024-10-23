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
계단 오르기 게임은 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임이다. 
<그림 1>과 같이 각각의 계단에는 일정한 점수가 쓰여 있는데 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 된다.

<그림 1>

예를 들어 <그림 2>와 같이 시작점에서부터 첫 번째, 두 번째, 네 번째, 여섯 번째 계단을 밟아 도착점에 도달하면 총 점수는 10 + 20 + 25 + 20 = 75점이 된다.

<그림 2>

계단 오르는 데는 다음과 같은 규칙이 있다.
-계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
-연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
-마지막 도착 계단은 반드시 밟아야 한다.
따라서 첫 번째 계단을 밟고 이어 두 번째 계단이나, 세 번째 계단으로 오를 수 있다. 하지만, 첫 번째 계단을 밟고 이어 네 번째 계단으로 올라가거나, 
첫 번째, 두 번째, 세 번째 계단을 연속해서 모두 밟을 수는 없다.

각 계단에 쓰여 있는 점수가 주어질 때 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성하시오.

/* 입력
입력의 첫째 줄에 계단의 개수가 주어진다.
둘째 줄부터 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수가 주어진다. 
계단의 개수는 300이하의 자연수이고, 계단에 쓰여 있는 점수는 10,000이하의 자연수이다.

/* 출력
첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 출력한다.

/* 제한
*/


int N;
vector<int> stairDP;

int max_stair_recursive(int i, vector<int>& stairs)
{
	// stairDP 데이터가 -1이 아니면 바로 반환
	if (stairDP[i] != -1)
	{
		return stairDP[i];
	}

	// 계단을 오르는 아이디어
	// 1층짜리 계단 오르는데 가장 큰 데이터
	if (i == 0)
	{
		return stairs[0];
	}

	// 2층짜리 계단 오르는데 가장 큰 데이터
	if (i == 1)
	{
		return stairs[0] + stairs[1];
	}

	// 3층짜리 계단 오르는데 가장 큰 데이터
	if (i == 2)
	{
		return stairDP[i] = max(stairs[0],stairs[1]) + stairs[2];
	}

	stairDP[i] = max(max_stair_recursive(i - 2, stairs), max_stair_recursive(i - 3, stairs) + stairs[i - 1]) + stairs[i];
	return stairDP[i];
}

int StairCount(vector<int>& stairs)
{
	int size = stairs.size();

	stairDP.assign(size, -1); // DEFAULT 값이 -1이다.

	return max_stair_recursive(size - 1, stairs);

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<int> stairs(N);
    for(int i=0; i<N; i++)
    {
        cin >> stairs[i];
    }

    cout << StairCount(stairs);
    return 0;
}