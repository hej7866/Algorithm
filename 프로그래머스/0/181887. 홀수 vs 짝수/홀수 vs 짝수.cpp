#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) 
{
    int a1 = 0;
    int a2 = 0;
    for(int i=0; i<num_list.size(); i++)
    {
        if(i%2 == 0)
        {
            a1 += num_list[i];
        }
        else
        {
            a2 += num_list[i];
        }
    }
    return a1 > a2 ? a1 : a2;
}