#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/* 문제 
온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다. 이때, 회원들을 나이가 증가하는 순으로, 
나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.


/* 입력
첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다. 나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 
이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다. 입력은 가입한 순서로 주어진다.

/* 출력
첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순, 나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.

/* 제한
 
*/


int main() 
{
    int N;
    cin >> N;

    vector<pair<int ,string>> info;
    int age;
    string name;

    // 입력
    for(int i=0; i<N; i++)
    {
        cin >> age >> name;
        info.push_back({age, name});
    }

    // 나이순으로 정렬, stable_sort를 사용해 가입 순서 유지
    stable_sort(info.begin(), info.end(), [](const pair<int, string> &a, const pair<int, string> &b) {
        return a.first < b.first;
    });

    // 출력
    for(auto &i : info)
    {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}