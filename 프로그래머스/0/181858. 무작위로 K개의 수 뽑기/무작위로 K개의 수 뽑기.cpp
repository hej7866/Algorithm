#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, int k) 
{
    //초기값 넣는 과정
    vector<int> answer;
    int temp = arr[0];
    answer.push_back(temp);
    // 배열 만드는 과정
    for(int &num : arr)
    {
        if(temp != num && find(answer.begin(), answer.end(), num) == answer.end())
        {
            answer.push_back(num);
            temp = num;
        }
        cout << temp << " ";
        if(answer.size() == k) break;
    }
    
    // 만약 만든 배열이 k보다 작다면 -1을 추가하는 과정
    while(answer.size() < k)
    {
        answer.push_back(-1);
    }
    return answer;
}