#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{

    int n = 0; // 2의 n거듭제곱을 담을 변수 n 선언
    while(true)
    {
        if((1 << n) >= arr.size()) // 1 << n은 비트연산자로 2의 n 거듭제곱을 나타냄
        {
            break;
        }
        n++;
    }
    double result = pow(2, n); // 2의n 거듭제곱을 result변수에 담고
    vector<int> vec(result,0); // result길이의 벡터를 만들고 모든값을 0 으로 초기화
    copy(arr.begin(), arr.end(), vec.begin()); // arr의 처음부터 끝까지를 복사하여 vec의 첫번째 인덱스부터 붙혀넣는다.
    return vec;
}