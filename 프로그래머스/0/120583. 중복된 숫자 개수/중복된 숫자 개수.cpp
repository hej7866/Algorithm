#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) 
{
    int count = 0;
    for(int &i : array)
    {
        if(i == n)
        {
            count++;
        }
    }
    return count;
}