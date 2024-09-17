#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> emergency) 
{
    vector<int> answer(emergency.size(),1);
    
    for(int i=0; i<emergency.size(); i++)
    {
        for(int &c : emergency)
        {
            if(emergency[i] < c)
            {
                answer[i]++;
            }
        }
    }
    return answer;
}