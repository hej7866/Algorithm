#include <iostream>
#include <vector>

using namespace std;

// 팩토리얼 계산 함수
long long factorial(int n) 
{
    long long result = 1;
    for (int i = 2; i <= n; ++i) 
    {
        result *= i;
    }
    return result;
}

vector<int> solution(int n, long long k) 
{
    vector<int> result;
    vector<int> numbers;
    
    // 1부터 n까지 숫자를 리스트에 추가
    for (int i = 1; i <= n; ++i) 
    {
        numbers.push_back(i);
    }
    
    // k는 0-based index로 계산
    k--; 
    
    // 각 자리의 숫자를 선택
    for (int i = n; i >= 1; --i) 
    {
        long long fact = factorial(i - 1);
        int index = k / fact; // 현재 자리에서 선택할 숫자의 인덱스
        result.push_back(numbers[index]);
        numbers.erase(numbers.begin() + index); // 사용한 숫자 제거
        k %= fact; // 남은 k값 업데이트
    }
    
    return result;
}