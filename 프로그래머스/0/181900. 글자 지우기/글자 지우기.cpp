#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<int> indices) 
{
    sort(indices.begin(), indices.end());
    
    string str = "";
    int idx = 0;
    for(int i=0; i<my_string.length(); i++)
    {
        if(indices[idx] == i)
        {
            idx++;
            continue;
        }
        str += my_string[i];
    }
    return str;
}