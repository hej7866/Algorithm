#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals)
{
    vector<int> answer;
    for(int i=0; i<intervals.size(); i++)
    {
        int s = intervals[i][0];
        int e = intervals[i][1];
        
        for(int j=s; j<=e; j++)
        {
            answer.push_back(arr[j]);
        }
    }
    return answer;
}