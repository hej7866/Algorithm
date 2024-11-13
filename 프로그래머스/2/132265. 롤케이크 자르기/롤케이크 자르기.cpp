#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping) 
{
    unordered_map<int, int> rightMap; // 오른쪽에 남은 토핑의 빈도
    unordered_map<int, int> leftMap;  // 왼쪽에 있는 토핑의 빈도
    
    // 1. 모든 토핑의 빈도를 오른쪽에 초기화
    for (int t : topping) 
    {
        rightMap[t]++;
    }
    
    int cnt = 0;
    
    // 2. 토핑을 왼쪽으로 하나씩 이동
    for (int t : topping) {
        // 현재 토핑을 오른쪽에서 제거
        rightMap[t]--;
        if (rightMap[t] == 0) 
        {
            rightMap.erase(t); // 빈도 0이면 제거
        }
        
        // 현재 토핑을 왼쪽에 추가
        leftMap[t]++;
        
        // 왼쪽과 오른쪽의 고유 토핑 종류 개수를 비교
        if (leftMap.size() == rightMap.size()) {
            cnt++;
        }
    }
    
    return cnt;
}
