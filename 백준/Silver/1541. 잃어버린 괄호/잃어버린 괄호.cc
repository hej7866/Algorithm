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

// 백준문제 - 잃어버린 괄호 [1541]

/* 문제 [Greedy]
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

/* 입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

/* 출력
첫째 줄에 정답을 출력한다.

/* 제한
*/



// 문자열을 특정 구분자로 분리하는 함수
vector<string> split(const string &str, char delimiter) 
{
    vector<string> tokens;
    string token;
    stringstream ss(str);
    
    while (getline(ss, token, delimiter)) 
    {
        tokens.push_back(token);
    }
    
    return tokens;
}

int main() 
{
    string expression;
    cin >> expression;

    // '-' 연산자를 기준으로 수식을 분리
    vector<string> minusSplit = split(expression, '-');
    
    // 첫 번째 그룹을 처리 (양수 부분)
    vector<string> firstGroup = split(minusSplit[0], '+');
    int total = 0;
    for(auto &numStr : firstGroup) 
    {
        total += stoi(numStr);
    }
    
    // 나머지 그룹을 처리 (모든 그룹을 빼야 함)
    for(int i = 1; i < minusSplit.size(); ++i) 
    {
        // 각 그룹 내의 '+' 연산자를 처리하여 합산
        vector<string> group = split(minusSplit[i], '+');
        int groupSum = 0;
        for(auto &numStr : group) 
        {
            groupSum += stoi(numStr);
        }
        total -= groupSum; // 전체에서 빼기
    }
    
    cout << total;
    return 0;
}