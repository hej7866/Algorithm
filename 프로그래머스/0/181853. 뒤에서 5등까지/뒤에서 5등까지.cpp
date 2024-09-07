#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> num_list) 
{
    vector<int> answer(5,0);
    sort(num_list.begin(),num_list.end());
    
    copy(num_list.begin(),num_list.begin()+6,answer.begin());
    return answer;
}