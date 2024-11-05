#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    vector<int> result(2);
    result[0] = 0;
    result[1] = sequence.size();
    int sum = 0;
    int start = 0;
    
    for (int end = 0; end < sequence.size(); end++) 
    {
        sum += sequence[end];
        
        // 합이 k를 초과할 경우 시작 포인터를 조정하여 합을 k 이하로 만듭니다
        while (sum > k && start <= end) 
        {
            sum -= sequence[start];
            start++;
        }

        // 합이 k와 같은 부분 배열을 찾았을 때
        if (sum == k) 
        {
            // 이전 부분 배열보다 짧은 경우 결과를 갱신
            if ((end - start) < (result[1] - result[0])) 
            {
                result[0] = start;
                result[1] = end;
            }
        }
    }
    
    return result;
}