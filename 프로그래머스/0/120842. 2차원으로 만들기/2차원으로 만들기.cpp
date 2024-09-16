#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) 
{
    vector<vector<int>> answer((num_list.size()/n),vector<int> (n,0));
    int i = 0;
    for(int j=0; j<num_list.size()/n; j++)
    {
        for(int k=0; k<n; k++)
        {
            answer[j][k] = num_list[i];
            i++;
        }
    }
    return answer;
}