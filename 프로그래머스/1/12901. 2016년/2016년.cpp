#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) 
{
    vector<pair<int, int>> vec =
    {
        {1, 31}, {2, 29}, {3, 31}, {4, 30},
        {5, 31}, {6, 30}, {7, 31}, {8, 31},
        {9, 30}, {10, 31}, {11, 30}, {12, 31},
    };
    
    vector<string> v = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int days = 0;
    for(int i=0; i<a-1; i++)
    {
        days += vec[i].second;
    }
    days += b - 1;
    cout << v[days%7];
    return v[days%7];;
}