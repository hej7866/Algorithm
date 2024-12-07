#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow; // 전체 카펫 크기

    for (int height = 3; height <= sqrt(total); ++height) {
        if (total % height == 0) { // 전체 면적이 나누어 떨어지는 경우
            int width = total / height;
            if ((width - 2) * (height - 2) == yellow) { // 노란색 크기 확인
                return {width, height};
            }
        }
    }
    return {}; // 조건을 만족하는 경우가 없을 때 (문제에서는 주어지지 않음)
}
