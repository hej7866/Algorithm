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


/* 문제 
1번부터 N번까지 N개의 풍선이 원형으로 놓여 있고. i번 풍선의 오른쪽에는 i+1번 풍선이 있고, 
왼쪽에는 i-1번 풍선이 있다. 단, 1번 풍선의 왼쪽에 N번 풍선이 있고, N번 풍선의 오른쪽에 1번 풍선이 있다. 
각 풍선 안에는 종이가 하나 들어있고, 종이에는 -N보다 크거나 같고, N보다 작거나 같은 정수가 하나 적혀있다. 이 풍선들을 다음과 같은 규칙으로 터뜨린다.
우선, 제일 처음에는 1번 풍선을 터뜨린다. 다음에는 풍선 안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터뜨린다.
양수가 적혀 있을 경우에는 오른쪽으로, 음수가 적혀 있을 때는 왼쪽으로 이동한다. 이동할 때에는 이미 터진 풍선은 빼고 이동한다.
예를 들어 다섯 개의 풍선 안에 차례로 3, 2, 1, -3, -1이 적혀 있었다고 하자.
이 경우 3이 적혀 있는 1번 풍선, -3이 적혀 있는 4번 풍선, -1이 적혀 있는 5번 풍선, 1이 적혀 있는 3번 풍선, 2가 적혀 있는 2번 풍선의 순서대로 터지게 된다.

/* 입력
첫째 줄에 자연수 N(1 ≤ N ≤ 1,000)이 주어진다. 다음 줄에는 차례로 각 풍선 안의 종이에 적혀 있는 수가 주어진다. 종이에 0은 적혀있지 않다.

/* 출력
첫째 줄에 터진 풍선의 번호를 차례로 나열한다.


/* 제한
*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    deque<pair<int, int>> balloons;  // (풍선 번호, 종이에 적힌 값)

    // 풍선 정보 입력
    for (int i = 1; i <= N; i++) 
    {
        int num;
        cin >> num;
        balloons.push_back({i, num});  // 풍선 번호와 값을 쌍으로 저장
    }

    vector<int> result;  // 터진 풍선의 번호를 저장할 벡터

    while (!balloons.empty()) 
    {
        // 현재 풍선 번호와 종이에 적힌 값을 가져옴
        int currentNum = balloons.front().first;
        int steps = balloons.front().second;
        
        // 현재 풍선을 터뜨리므로 결과에 추가
        result.push_back(currentNum);
        balloons.pop_front();  // 풍선을 제거

        if (balloons.empty()) { break; }  // 풍선이 더 없으면 종료
        
        // 양수면 오른쪽(앞으로), 음수면 왼쪽(뒤로) 이동
        if (steps > 0) 
        {
            // 오른쪽(앞으로) steps-1 만큼 이동
            for (int i = 0; i < steps - 1; i++) 
            {
                balloons.push_back(balloons.front());  // 앞에서 꺼내서 뒤로 보냄
                balloons.pop_front();  // 앞에서 제거
            }
        } 
        else 
        {
            // 왼쪽(뒤로) |steps| 만큼 이동
            for (int i = 0; i < -steps; i++) 
            {
                balloons.push_front(balloons.back());  // 뒤에서 꺼내서 앞으로 보냄
                balloons.pop_back();  // 뒤에서 제거
            }
        }
    }

    // 결과 출력
    for (int num : result) 
    {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}