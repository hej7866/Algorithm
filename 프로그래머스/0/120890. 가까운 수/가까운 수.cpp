#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> array, int n) 
{      
    sort(array.begin(), array.end());
    vector<int> len;
    for(int i=0; i<array.size(); i++)
    {
        len.push_back(abs(array[i]-n));
    }
    auto min_it = min_element(len.begin(),len.end());
    
    int index = 0;
    for(int i=0; i<len.size(); i++)
    {
        if(len[i] == *min_it)
        {
            index = i;
            break;
        }
    }
    return array[index];
}