#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) 
{
    vector<int> even_odd_vec(2,0);
    for(int &i : num_list)
    {
        if(i%2 == 0) {even_odd_vec[0]++;}
        else if(i%2 == 1) {even_odd_vec[1]++;}
    }
    return even_odd_vec;
}