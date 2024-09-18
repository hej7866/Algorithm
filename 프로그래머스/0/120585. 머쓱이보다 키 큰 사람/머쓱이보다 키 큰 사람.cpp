#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int height) 
{
    array.push_back(height);
    sort(array.begin(), array.end());
    int index = 0;
    for(int i=0; i<=array.size(); i++)
    {
        if(array[i] == height)
        {
            index = i;
        }
    }
    return array.size() - index - 1;
}