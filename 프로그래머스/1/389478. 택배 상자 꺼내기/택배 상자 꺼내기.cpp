#include <iostream>
using namespace std;

int solution(int n, int w, int num) {
    // 1. 전체 층 수 구하기
    int fullRows = n / w;        // 완전히 채워진 층의 수
    int r = n % w;               // 마지막 층에 채워진 상자 수 (0이면 마지막 층도 full)
    int h = (r == 0) ? fullRows : fullRows + 1;
    
    // 2. target 상자의 위치 계산 (행, 열)
    int targetRow = (num - 1) / w;      // 0-indexed 층 번호 (바닥이 0층)
    int pos = (num - 1) % w;            // 해당 층에서의 순서 (0-indexed)
    int targetCol;
    if (targetRow % 2 == 0) {           // 짝수 층: 왼쪽→오른쪽
        targetCol = pos;
    } else {                          // 홀수 층: 오른쪽→왼쪽
        targetCol = (w - 1) - pos;
    }
    
    // 3. target 상자 위(포함)로 같은 열에 있는 상자 개수 계산
    int count = 0;
    // target 상자가 있는 층부터 최상층까지 확인
    for (int row = targetRow; row < h; row++) {
        int rowCount; // 해당 층에 채워진 상자 개수
        if (row < fullRows) {         // 완전히 채워진 층
            rowCount = w;
        } else {                      // 마지막 층 (partial)
            rowCount = r;
        }
        
        // 층별 채우는 방식에 따른 유효 열 범위 확인
        if (row % 2 == 0) { // 짝수 층: 채워진 열은 0 ~ rowCount-1
            if (targetCol < rowCount)
                count++;
        } else {          // 홀수 층: 채워진 열은 (w - rowCount) ~ (w - 1)
            if (targetCol >= w - rowCount)
                count++;
        }
    }
    
    return count;
}
