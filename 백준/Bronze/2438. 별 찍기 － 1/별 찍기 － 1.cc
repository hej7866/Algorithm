#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

 
/* 문제 
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
*/


/* 입력
첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제
*/


/* 출력
첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.
*/


/* 제한

*/


int main()
{
    int N;
    cin >> N;

    string star = "";

    for(int i=0; i<N; i++)
    {
        star += "*";
        cout << star << "\n";
    }
    return 0;
}

