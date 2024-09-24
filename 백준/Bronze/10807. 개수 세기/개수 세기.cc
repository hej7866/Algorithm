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
    int size;
    cin >> size;
    vector<int> vec(size);

    int a;
    for(int i=0; i<size; i++)
    {
        cin >> a; 
        vec[i] = a;
    }

    int test;
    cin >> test;
    int count = 0;
    for(int &i : vec)
    {
        if(i == test)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}

