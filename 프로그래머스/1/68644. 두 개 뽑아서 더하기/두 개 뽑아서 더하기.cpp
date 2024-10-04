#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) 
{
    set<int> set;
    
    for(int i=0; i<numbers.size() - 1; i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            set.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> ans;
    for(auto s : set)
    {
        ans.push_back(s);
    }
    return ans;
}