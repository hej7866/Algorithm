#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> names) 
{
    vector<string> v;
    for(int i=0; i<names.size(); i++)
    {
        if(i%5 == 0)
        {
            v.push_back(names[i]);
        }
    }
    return v;
}