#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) 
{
    vector<int> answer;
 
    for(int i=l; i<=r; i++)
    {
        string i_str = to_string(i);
        bool isCheck = true;
        for(char &c : i_str)
        {
            if(c != '5' && c != '0')
            {
                isCheck = false;
            }
        }
        if(isCheck) { answer.push_back(i); }
    }
    if(answer.empty()) { answer.push_back(-1); }
    return answer;
}