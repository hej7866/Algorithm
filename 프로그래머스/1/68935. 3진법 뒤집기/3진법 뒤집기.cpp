#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) 
{
    vector<int> vec;
    while(n > 0)
    {
        vec.push_back(n%3);
        n /= 3;
    }
    
    for(int &i : vec)
    {
        cout << i << " ";
    }
    
    int ans = 0;
    int a = 1;
    for(int i=vec.size()-1; i>=0; i--)
    {
        ans += vec[i] * a;
        a *= 3; 
    }
    return ans;
}