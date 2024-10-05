#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) 
{
    int len = board.size();
    vector<stack<int>> stacks(len);

    // 배열의 요소를 각 스택에 분배
    for (int i = len-1; i >= 0; i--) 
    {
        for (int j = 0; j < len; ++j) 
        {
            stacks[j].push(board[i][j]); // j번째 스택에 i번째 행의 요소 추가
        }
    }
    
    for (int i = 0; i < len; ++i) 
    {
        while(stacks[i].top() == 0) 
        {
            stacks[i].pop();
        } 
    }
    
    int count = 0;
    vector<int> vec;
    for(int &i : moves)
    {
        if(!stacks[i-1].empty())
        {
            if(!vec.empty() && vec.back() == stacks[i-1].top())
            {
                vec.pop_back();
                count++;
            }
            else if(vec.empty() || vec.back() != stacks[i-1].top())
            {     
                vec.push_back(stacks[i-1].top());
            }
            stacks[i-1].pop();
        }
    }
    
    // 디버깅
    for (int i = 0; i < len; ++i) 
    {
        cout << (i + 1) << "번 스택: ";
        while (!stacks[i].empty()) 
        {
            cout << stacks[i].top() << " ";
            stacks[i].pop();
        }
        cout << endl;
    }
    
    // 디버깅
    for(int v : vec)
    {
        cout << v << " ";
    }
    
    return count  * 2;
}