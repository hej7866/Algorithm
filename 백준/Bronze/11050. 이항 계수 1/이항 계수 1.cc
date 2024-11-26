#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
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

// 문제 - 조합론

/* 문제 - 이항 계수 1 [11050]
자연수 N과 정수 K가 주어졌을 때 이항 계수 binom{N}{K}를 구하는 프로그램을 작성하시오.

/*
입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)

/* 출력
 binom{N}{K}를 출력한다.


/* 제한
*/



int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,K;
    cin >> N >> K;
    int n,k,r;
    n = 1;
    k = 1;
    r = 1;
    for(int i=1; i<=N; i++)
    {
        n *= i;
    }
    for(int i=1; i<=K; i++)
    {
        k *= i;
    }
    for(int i=1; i<=N-K; i++)
    {
        r *= i;
    }   
    int t = k * r;
    cout << n/t;
    return 0;
}