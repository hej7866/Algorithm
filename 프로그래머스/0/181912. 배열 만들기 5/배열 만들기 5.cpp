#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) 
{
    vector<int> result;
    for(int i=0; i<intStrs.size(); i++)
    { 
        string subStr = intStrs[i].substr(s,l);
        if(stoi(subStr) > k)
        {
            result.push_back(stoi(subStr));
        }
    }
    return result;    
}