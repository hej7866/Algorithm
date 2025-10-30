#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) 
{
    vector<int> v(52,0);
    
    for(char c : my_string)
    {
        if(isupper(c))
        {
            v[c-65]++;
        }
        else if(islower(c))
        {
            v[c-71]++;
        }
    }
    
    return v;
}