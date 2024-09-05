#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) 
{
    string odd_temp = "";
    string even_temp = "";
    for(int i=0; i<num_list.size(); i++)
    {
        if(num_list[i]%2 == 1)
        {
            odd_temp += to_string(num_list[i]);
        }
        else
        {
            even_temp += to_string(num_list[i]);
        }
    }
    return stoi(odd_temp) + stoi(even_temp);
}