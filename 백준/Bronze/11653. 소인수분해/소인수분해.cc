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

// 백준문제 - 소인수분해 [11653]

/* 문제 [약수, 배수와 소수]
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

/*
입력
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

/* 출력
N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다.

/* 제한
*/

int main()
{
    int N;
    cin >> N;

    int d = 2;
    while(N > 1)
    {
        if(N%d == 0)
        {
            cout << d << "\n";
            N /= d; 
        }
        else
        {
            d++;
        }
    }
    return 0;
}