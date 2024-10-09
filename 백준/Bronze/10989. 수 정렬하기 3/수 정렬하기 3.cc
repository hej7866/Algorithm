#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


/* 문제 
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.


/* 입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.




/* 출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/


/* 제한
 
*/


int main() 
{
    int N;
    cin >> N;

    // 1부터 10,000까지의 숫자 범위의 카운트 배열 생성
    vector<int> count(10001, 0);

    // 입력을 받아 카운트 배열에 각 숫자의 빈도를 기록
    int num;
    for (int i = 0; i < N; i++) 
    {
        cin >> num;
        count[num]++;
    }

    // 카운트 배열을 순회하며, 각 숫자를 등장한 횟수만큼 출력
    for (int i = 1; i <= 10000; i++) 
    {
        while (count[i] > 0) 
        {
            cout << i << "\n";
            count[i]--;
        }
    }

    return 0;
}
