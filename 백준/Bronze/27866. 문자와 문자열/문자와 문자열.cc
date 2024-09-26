#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

 
/* 문제 
단어 S와 정수 i가 주어졌을 때, S의 i번째 글자를 출력하는 프로그램을 작성하시오.
*/


/* 입력
첫째 줄에 영어 소문자와 대문자로만 이루어진 단어 S가 주어진다. 단어의 길이는 최대 1000DLEK.
둘째 줄에 정수 i가 주어진다.
*/


/* 출력
첫째 줄에 새로운 평균을 출력한다. 실제 정답과 출력값의 절대오차 또는 상대오차가 10-2 이하이면 정답이다.
*/


/* 제한

*/


int main()
{
    string S;
    cin >> S;

    int i;
    cin >> i;

    cout << S[i-1];
    return 0;
}


