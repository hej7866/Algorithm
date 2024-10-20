#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int N = nums.size() / 2;
    set<int> set;
    for(int i : nums)
    {
        set.insert(i);
    }
    cout << set.size();
    
    return set.size() >= N ? N : set.size();
}