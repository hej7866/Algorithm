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


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, int> nameToNumber;
    vector<string> numberToName(N + 1);

    // 도감 입력
    for (int i = 1; i <= N; ++i) {
        string name;
        cin >> name;
        nameToNumber[name] = i;
        numberToName[i] = name;
    }

    // 질문 처리
    for (int i = 0; i < M; ++i) {
        string query;
        cin >> query;

        if (isdigit(query[0])) {
            // 번호로 이름 찾기
            int number = stoi(query);
            cout << numberToName[number] << "\n";
        } else {
            // 이름으로 번호 찾기
            cout << nameToNumber[query] << "\n";
        }
    }

    return 0;
}