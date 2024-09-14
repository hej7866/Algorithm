#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) 
{
    vector<int> vec;
    int i = 1;
    while(vec.size() < 101)
    {
        string str = to_string(i);
        if(i%3 != 0 && str.find('3') == string::npos)
        {
            vec.push_back(i);
        }
        else
        {
            while(i%3 == 0 || str.find('3') != string::npos)
            {
                i++;
                str = to_string(i);
            }
            vec.push_back(i);
        }
        i++;
    }
    for(int &v : vec)
    {
        cout << v << " ";
    }
    return vec[n-1];
}