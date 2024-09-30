#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

 
/* 문제 
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.
*/


/* 입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.
*/


/* 출력
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.
*/


/* 제한

*/


int main() 
{
    int N;
    cin >> N;

    // 상단 부분
    for (int i = 0; i < N; i++) 
    {
        // 공백 출력
        for (int j = 0; j < N - i - 1; j++) 
        {
            cout << " ";
        }
        // 별 출력
        for (int j = 0; j < 2 * i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    // 하단 부분
    for (int i = N - 2; i >= 0; i--) 
    {
        // 공백 출력
        for (int j = 0; j < N - i - 1; j++) 
        {
            cout << " ";
        }
        // 별 출력
        for (int j = 0; j < 2 * i + 1; j++) 
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}

