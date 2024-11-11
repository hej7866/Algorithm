#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int solution(int x, int y, int n) 
{
    queue<pair<int, int>> q; // (현재 값, 연산 횟수)
    unordered_set<int> visited; // 방문 체크용 집합

    q.push({x, 0});
    visited.insert(x);

    while (!q.empty()) 
    {
        int current = q.front().first;
        int operations = q.front().second;
        q.pop();

        // y에 도달하면 연산 횟수 반환
        if (current == y) 
        {
            return operations;
        }

        // 가능한 세 가지 연산
        int next_values[] = {current + n, current * 2, current * 3};

        for (int next : next_values) 
        {
            // 다음 값이 y를 넘지 않고, 방문하지 않았다면 큐에 추가
            if (next <= y && visited.find(next) == visited.end()) 
            {
                q.push({next, operations + 1});
                visited.insert(next);
            }
        }
    }

    // y에 도달할 수 없으면 -1 반환
    return -1;
}