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
재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.
크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.

***
* *
***
N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다. 예를 들어 크기 27의 패턴은 예제 출력 1과 같다.


/* 입력
첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3^k이며, 이때 1 ≤ k < 8이다.

/* 출력
첫째 줄부터 N번째 줄까지 별을 출력한다.


/* 제한
*/
void StarPattern(vector<vector<char>>& pattern, int size, int x, int y)
{
    if (size == 1) 
    {
        pattern[x][y] = '*'; // 기본패턴 (제일 작은 단위)
        return;
    }   

    int newSize = size / 3; // 현재 정사각형을 9개로 나눈다.
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i == 1 && j == 1)
            {
                continue;
            }
            StarPattern(pattern,  newSize, x + i * newSize, y  + j * newSize);
        }
    }
    
}

void PrintPattern(vector<vector<char>>& pattern, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            cout << pattern[i][j];
        }
        cout << "\n";
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<char>> pattern(N, vector<char>(N, ' '));

    StarPattern(pattern, N, 0, 0);

    PrintPattern(pattern, N);

    return 0;
}