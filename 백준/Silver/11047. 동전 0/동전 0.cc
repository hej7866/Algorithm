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


/* 문제 [Greedy]
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

/* 입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
둘째 줄부터 N개의 줄에 동전의 가치 A_i가 오름차순으로 주어진다. (1 ≤ A_i ≤ 1,000,000, A_1 = 1, i ≥ 2인 경우에 Ai는 A_i-1의 배수)

/* 출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

/* 제한
*/

int cnt = 0;

int Solution_11047(vector<int>& vec, int K)
{
    int size = vec.size();
    int idx = size - 1;
    
    int sum = 0;
    while(true)
    {
        if(sum + vec[idx] > K)
        {
            idx--;
        }
        else
        {
            while(true)
            {
                sum += vec[idx];
                cnt++;
                if(sum > K)
                {
                    sum -= vec[idx];
                    cnt--;
                    break;
                }
            }
        }

        if(sum == K) break; 
    }
    return cnt;
}


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> value(N);
    for(int i=0; i<N; i++)
    {
        cin >> value[i];
    }
    sort(value.begin(), value.end());
    cout << Solution_11047(value, K);
    
    return 0;
}