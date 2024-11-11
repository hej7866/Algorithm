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

// 백준문제 - 소수 찾기 [1978]

/* 문제 [소수 찾기]
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

/*
입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.


/* 출력
주어진 수들 중 소수의 개수를 출력한다.

/* 제한
*/

int N;
int cnt = 0;

int main() 
{
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++)
    {
        cin >> vec[i];
    }

    for(int n : vec)
    {
        if(n == 1) continue;
        bool isBool = false;
        for(int i=2; i<n; i++)
        {
            if(n % i == 0) 
            {
                isBool = true;
                break;
            }
        }
        if(!isBool) cnt++;
    }
    cout << cnt;
    return 0;
}