#include <iostream>
using namespace std;

// 하노이의 탑 이동을 재귀적으로 수행하는 함수
void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        // 원판 하나를 목적지로 옮김
        cout << from << " " << to << '\n';
        return;
    }
    // Step 1: n-1개의 원판을 보조 탑으로 옮김
    hanoi(n - 1, from, aux, to);
    
    // Step 2: 가장 큰 원판을 목적지로 옮김
    cout << from << " " << to << '\n';
    
    // Step 3: 보조 탑에 있던 n-1개의 원판을 목적지로 옮김
    hanoi(n - 1, aux, to, from);
}

int main() {
    int N;
    cin >> N;
    
    // 총 이동 횟수는 2^N - 1
    cout << (1 << N) - 1 << '\n';  // (1 << N)은 2^N을 의미
    
    // 하노이 탑 수행 (첫 번째 장대: 1, 세 번째 장대: 3, 두 번째 장대: 2)
    hanoi(N, 1, 3, 2);
    
    return 0;
}
