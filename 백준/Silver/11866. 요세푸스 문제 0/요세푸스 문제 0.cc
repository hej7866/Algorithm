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

using namespace std;


/* 문제 
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 
원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

/* 입력
첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 1,000)

/* 출력
예제와 같이 요세푸스 순열을 출력한다.

/* 제한
*/



int main() 
{
    ios::sync_with_stdio(false);  // 입출력 속도 최적화
    cin.tie(NULL); 

    int N, K;
    cin >> N >> K;

    vector<int> vec;
    for(int i=1; i<=N; i++)
    {
        vec.push_back(i);
    }

    int count = 1;
    auto it = vec.begin();
    cout << "<";
    while(!vec.empty())
    {
        if(count == K)
        {
            if(vec.size() > 1)
            {
                cout << *it << ", ";
            }
            else if(vec.size() == 1)
            {
                cout << *it << ">";
            }
            vec.erase(it);
            if(it == vec.end())
            {
                it = vec.begin();
            }
            count = 1;
        }
        else
        {
            count++;
            it++;
            if(it == vec.end())
            {
                it = vec.begin();
            }
        }
    }
    return 0;
}