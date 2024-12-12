#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) 
{
    // 논문 인용 횟수를 내림차순으로 정렬
    sort(citations.rbegin(), citations.rend());
    
    int hIndex = 0;
    for (int i = 0; i < citations.size(); i++) 
    {
        // 현재 인용 횟수와 논문 수를 비교
        if (citations[i] >= i + 1) 
        {
            hIndex = i + 1;
        } 
        else 
        {
            break;
        }
    }
    return hIndex;
}
