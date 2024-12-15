#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> counts;
    for (const auto& cloth : clothes) {
        counts[cloth[1]]++;
    }

    int result = 1;
    for (const auto& pair : counts) {
        result *= (pair.second + 1);
    }

    return result - 1;
}