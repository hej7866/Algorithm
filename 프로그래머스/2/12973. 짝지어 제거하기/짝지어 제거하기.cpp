#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    stack<char> st;

    // 문자열 순회
    for (char c : s) 
    {
        if (!st.empty() && st.top() == c) 
        {
            st.pop();
        } 
        else 
        {
            st.push(c);
        }
    }

    // 스택이 비어 있으면 1, 그렇지 않으면 0 반환
    return st.empty() ? 1 : 0;
}
