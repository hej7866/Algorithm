#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> dots) {
    // 각각 페어가 되는 경우의 수
    vector<vector<int>> pairs = {
        {0, 1, 2, 3},
        {0, 2, 1, 3},
        {0, 3, 1, 2}
    };

    for (vector<int> xy : pairs) {        
        int mul1 = (dots[xy[1]][1] - dots[xy[0]][1]) * (dots[xy[3]][0] - dots[xy[2]][0]);
        int mul2 = (dots[xy[1]][0] - dots[xy[0]][0]) * (dots[xy[3]][1] - dots[xy[2]][1]);

        if (mul1 == mul2) {
            return 1;
        }
    }

    return 0;
}