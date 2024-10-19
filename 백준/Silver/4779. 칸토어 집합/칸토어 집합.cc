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


/* 문제 [재귀]
칸토어 집합은 0과 1사이의 실수로 이루어진 집합으로, 구간 [0, 1]에서 시작해서 각 구간을 3등분하여 가운데 구간을 반복적으로 제외하는 방식으로 만든다.
전체 집합이 유한이라고 가정하고, 다음과 같은 과정을 통해서 칸토어 집합의 근사를 만들어보자.

1. -가 3N개 있는 문자열에서 시작한다.
2. 문자열을 3등분 한 뒤, 가운데 문자열을 공백으로 바꾼다. 이렇게 하면, 선(문자열) 2개가 남는다.
3. 이제 각 선(문자열)을 3등분 하고, 가운데 문자열을 공백으로 바꾼다. 이 과정은 모든 선의 길이가 1일때 까지 계속 한다.

예를 들어, N=3인 경우, 길이가 27인 문자열로 시작한다.

---------------------------
여기서 가운데 문자열을 공백으로 바꾼다.

---------         ---------
남은 두 선의 가운데 문자열을 공백으로 바꾼다.

---   ---         ---   ---
한번 더

- -   - -         - -   - -
모든 선의 길이가 1이면 멈춘다. N이 주어졌을 때, 마지막 과정이 끝난 후 결과를 출력하는 프로그램을 작성하시오.


/* 입력
입력을 여러 줄로 이루어져 있다. 각 줄에 N이 주어진다. 파일의 끝에서 입력을 멈춘다. N은 0보다 크거나 같고, 12보다 작거나 같은 정수이다.

/* 출력
입력으로 주어진 N에 대해서, 해당하는 칸토어 집합의 근사를 출력한다.


/* 제한
*/


void Cantor(int level, int max_level, int start, int end)
{
    if (level == max_level) 
    {
        // 최종 깊이에 도달했을 때, 구간을 출력
        for (int i = start; i < end; ++i) 
        {
            cout << "-";
        }
    } 
    else 
    {
        // 1/3씩 나누고 가운데를 제거한 후 재귀 호출
        int third = (end - start) / 3;
        
        // 왼쪽 1/3
        Cantor(level + 1, max_level, start, start + third);
        
        // 가운데 1/3은 공백으로 남김 (제거)
        for (int i = start + third; i < start + 2 * third; i++) 
        {
            cout << " ";
        }
        
        // 오른쪽 1/3
        Cantor(level + 1, max_level, start + 2 * third, end);
    }

}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while(cin >> N)
    {
        Cantor(0, N, 0, pow(3,N));
        cout << "\n";
    }

   

    return 0;
}