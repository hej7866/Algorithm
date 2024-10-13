#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;


/* 문제 
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.
1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
3: 스택에 들어있는 정수의 개수를 출력한다.
4: 스택이 비어있으면 1, 아니면 0을 출력한다.
5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.


/* 입력
첫째 줄에 명령의 수 N이 주어진다. (1 ≤ N ≤ 1,000,000)
둘째 줄부터 N개 줄에 명령이 하나씩 주어진다.
출력을 요구하는 명령은 하나 이상 주어진다.

/* 출력
출력을 요구하는 명령이 주어질 때마다 명령의 결과를 한 줄에 하나씩 출력한다.

/* 제한
*/


int main() 
{

    ios::sync_with_stdio(false);  // 입출력 속도 최적화
    cin.tie(NULL); 
    
    int N;
    cin >> N;

    stack<int> st;
    int c;
    for(int i=0; i<N; i++)
    {
        cin >> c;
        if(c == 1)
        {
            int t;
            cin >> t;
            st.push(t);
        }
        else if(c == 2)
        {
            if(!st.empty())
            {
                cout << st.top() << "\n";
                st.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        } 
        else if(c == 3)
        {
            cout << st.size() << "\n";
        }
        else if(c == 4)
        {
            if(st.empty())
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if(c == 5)
        {
            if(!st.empty())
            {
                cout << st.top() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}