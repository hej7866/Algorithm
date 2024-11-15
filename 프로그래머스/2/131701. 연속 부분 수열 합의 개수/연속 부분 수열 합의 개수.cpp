#include <vector>
#include <unordered_set>

using namespace std;

int solution(std::vector<int> elements) 
{
    int n = elements.size();
    unordered_set<int> unique_sums;

    // 배열을 두 번 이어붙여서 원형 수열 처리
    vector<int> extended_elements(elements.begin(), elements.end());
    extended_elements.insert(extended_elements.end(), elements.begin(), elements.end());

    // 길이가 1부터 n까지의 모든 부분 수열의 합 계산
    for (int len = 1; len <= n; len++) 
    {
        for (int start = 0; start < n; start++) 
        {
            int sum = 0;
            for (int i = 0; i < len; ++i) 
            {
                sum += extended_elements[start + i];
            }
            unique_sums.insert(sum);
        }
    }

    return unique_sums.size();
}