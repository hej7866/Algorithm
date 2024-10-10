#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


/* 문제 
2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.


/* 입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. 
(-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.



/* 출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.


/* 제한
 
*/


int main() 
{
    int N;
    cin >> N;

    int xi, yi;
    vector<pair<int, int>> pos;
    for(int i=0; i<N; i++)
    {
        cin >> xi >> yi;
        pos.push_back({xi,yi});
    }

    sort(pos.begin(), pos.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) 
        {
            return a.second < b.second;  // x가 같다면 y 기준으로 오름차순 정렬
        }
        return a.first < b.first;  // x 기준으로 오름차순 정렬
    });

    for(auto &p : pos)
    {
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}
