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

/* 문제 - 녹색거탑 [24723]
2022년 봄 어느 날.

전 세계에 코딩괴물이 나타났다.

그리고 코딩괴물과 함께 갑작스레 등장한 '그것'...

바로 녹색거탑이다.

녹색거탑의 정상에서는 매년 NAVER가 개최하는 개발자 컨퍼런스 DEVIEW가 열린다. 이 DEVIEW에 참여하면, 코딩에 깊은 깨달음을 얻어 코딩괴물이 될 수 있다고 전해진다. 그리고 코딩괴물은 녹색거탑의 정상에서 내려온다. 예전부터 전해 내려오는 D2 비전서에 의하면, 코딩괴물이 녹색거탑의 정상에서 내려오는 경우의 수를 파악한 사람은, 개발자 컨퍼런스 DEVIEW에 참여할 수 있다 한다. 그리고 DEVIEW에 참여해 본인도 코딩괴물이 될 수 있다!

녹색거탑은 위 그림과 같이 규칙적으로 쌓여있다.

그림의 시야에 보이지 않는 블록은 없다.
그림의 시야에 보이는 블록의 윗면만 이용해 녹색거탑을 내려올 수 있다.
녹색거탑이 
N층이면, 총 N개의 블록을 이용한 최단 경로로만 내려온다.
녹색거탑을 내려올 때는 정상에서 시작해 노란색 바닥까지, 항상 인접한 아래층의 블록으로만 내려온다.
녹색거탑을 정복하고 DEVIEW에 참여하자.

/*
입력
녹색거탑의 높이를 나타내는 정수 N이 주어진다. (1 <= N <= 5)
N

/* 출력
녹색거탑의 정상에서 바닥으로 내려오는 경우의 수를 출력한다.


/* 제한
*/



int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    int ans = 1;
    for(int i=0; i<N; i++)
    {
        ans *= 2;
    }
    cout << ans;

    return 0;
}