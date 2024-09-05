#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) 
{
    int num_list_multiply = 1;
    int num_list_sum = 0;
    for(int i=0; i<num_list.size(); i++)
    {
        num_list_multiply *= num_list[i];
        num_list_sum += num_list[i];
    }
    return (num_list_multiply < num_list_sum * num_list_sum) ? 1 : 0;
}