#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_wine(const vector<int>& wines) {
    int n = wines.size();
    
    // 예외 처리: 포도주 잔의 개수가 1개 또는 2개인 경우
    if (n == 1) {
        return wines[0];
    } else if (n == 2) {
        return wines[0] + wines[1];
    }
    
    // dp 테이블 초기화
    vector<int> dp(n, 0);
    dp[0] = wines[0];
    dp[1] = wines[0] + wines[1];
    dp[2] = max({wines[0] + wines[1], wines[0] + wines[2], wines[1] + wines[2]});
    
    // dp 점화식 적용
    for (int i = 3; i < n; ++i) {
        dp[i] = max({dp[i - 1], dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i]});
    }
    
    // 최대로 마실 수 있는 포도주 양 반환
    return dp[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> wines(n);
    for (int i = 0; i < n; ++i) {
        cin >> wines[i];
    }
    
    // 결과 출력
    cout << max_wine(wines) << endl;
    return 0;
}