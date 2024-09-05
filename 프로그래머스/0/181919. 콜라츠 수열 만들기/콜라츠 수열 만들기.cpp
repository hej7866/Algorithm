#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) 
{
    vector<int> answer;
    answer.push_back(n);
    
    while(answer.back() != 1)
    {
        int curr = answer.back();
        if(curr%2 == 0)
        {
            answer.push_back(curr/2);
        }
        else
        {
            answer.push_back(curr * 3 + 1);
        }
    }
    return answer;
}