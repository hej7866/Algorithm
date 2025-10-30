#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string my_string, vector<int> indices) 
{
    sort(indices.begin(), indices.end()); // 오름차순 정렬
    for(int i=0; i<indices.size(); i++)
    {
        my_string.erase(my_string.begin() + indices[i]);
        for(int j = i + 1; j<indices.size(); j++)
        {
            indices[j]--;
        }
    }
    return my_string;
}