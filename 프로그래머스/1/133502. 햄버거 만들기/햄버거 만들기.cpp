#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> ingredient) 
{
    string str = "";
    string hbg = "1231";
    
    int count = 0;
    for(int i=0; i<ingredient.size(); i++)
    {
        if(str.length() < 8)
        {
            str += to_string(ingredient[i]);
        }
        else if(str.length() >= 8)
        {
            str += to_string(ingredient[i]);
            str.erase(0,1);
        }
        
        while(str.find(hbg) != string::npos)
        {
            size_t pos = str.find(hbg);
            str.erase(pos, hbg.length());
            count++;
        }
    }
    return count;
}