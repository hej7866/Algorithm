#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 100x100 도화지 초기화
    vector<vector<int>> paper(100, vector<int>(100, 0));

    for (int i = 0; i < N; i++) 
    {
        int x, y;
        cin >> x >> y;

        // 색종이를 붙일 10x10 영역을 1로 표시
        for (int j = x; j < x + 10; j++) 
        {
            for (int k = y; k < y + 10; k++) 
            {
                paper[j][k] = 1;
            }
        }
    }

    // 검은 영역의 넓이 계산
    int area = 0;
    for (int i = 0; i < 100; i++) 
    {
        for (int j = 0; j < 100; j++)
        {
            area += paper[i][j]; // 1인 부분의 수를 센다
        }
    }

    cout << area << endl; // 최종 검은 영역의 넓이 출력
    return 0;
}