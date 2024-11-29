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

// 문제 - 일반 수학

/* 문제 - 중앙 이동 알고리즘 [2903]
상근이는 친구들과 함께 SF영화를 찍으려고 한다. 이 영화는 외계 지형이 필요하다. 실제로 우주선을 타고 외계 행성에 가서 촬영을 할 수 없기 때문에, 컴퓨터 그래픽으로 CG처리를 하려고 한다.
외계 지형은 중앙 이동 알고리즘을 이용해서 만들려고 한다.
알고리즘을 시작하면서 상근이는 정사각형을 이루는 점 4개를 고른다. 그 후에는 다음과 같은 과정을 거쳐서 지형을 만든다.
정사각형의 각 변의 중앙에 점을 하나 추가한다.
정사각형의 중심에 점을 하나 추가한다.
초기 상태에서 위와 같은 과정을 한 번 거치면 총 4개의 정사각형이 새로 생긴다. 이와 같은 과정을 상근이가 만족할 때 까지 계속한다.
		
초기 상태 - 점 4개	1번 - 점 9개	2번 - 25개
상근이는 어떤 점은 한 개 보다 많은 정사각형에 포함될 수 있다는 사실을 알았다. 메모리 소모량을 줄이기 위해서 중복하는 점을 한 번만 저장하려고 한다. 과정을 N번 거친 후 점 몇 개를 저장해야 하는지 구하는 프로그램을 작성하시오.

/*
입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 15)

/* 출력
첫째 줄에 과정을 N번 거친 후 점의 수를 출력한다.


/* 제한
*/




int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int a = 2;

    for(int i=1; i<=N; i++)
    {
        a = a + (a - 1);
    }
    cout << a * a;
    return 0;
}