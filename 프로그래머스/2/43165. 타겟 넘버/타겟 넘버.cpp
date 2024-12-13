#include <iostream>
#include <vector>

using namespace std;

int DFS(const vector<int>& numbers, int target, int index, int current) {
    if (index == numbers.size()) {
        if (current == target) {
            return 1;
        } else {
            return 0;
        }
    }

    int plusResult = DFS(numbers, target, index + 1, current + numbers[index]);
    int minusResult = DFS(numbers, target, index + 1, current - numbers[index]);

    return plusResult + minusResult;
}

int solution(vector<int> numbers, int target) {
    return DFS(numbers, target, 0, 0);
}
