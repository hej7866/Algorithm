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

// 문제 - 집합과 맵

/* 문제 - 듣보잡 [1764]
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

/*
입력
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 
이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.
듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

/* 출력
듣보잡의 수와 그 명단을 사전순으로 출력한다. 

/* 제한
*/


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;
    vector<string> vec1(N);
    for(int i=0; i<N; i++)
    {
        cin >> vec1[i];
    }

    unordered_set<string> set1;
    for(int i=0; i<M; i++)
    {
        string tmp;
        cin >> tmp; 
        set1.insert(tmp);
    } 

    vector<string> result;
    for(string v : vec1)
    {
        int size = set1.size();
        set1.insert(v);
        if(size == set1.size())
        {
            result.push_back(v);
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for(string r : result)
    {
        cout << r << "\n";
    }
    return 0;
}