#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) 
{
    string str1 = "";
    string str2 = "";
    
    for(int i=1; i<food.size(); i++)
    {
        int f = food[i] / 2;
        for(int j=0; j<f; j++)
        {
            str1 += to_string(i);
        }
    }
    for(int i=food.size() - 1; i>=1; i--)
    {
        int f = food[i] / 2;
        for(int j=0; j<f; j++)
        {
            str2 += to_string(i);
        }
    }
    return str1 + "0" + str2;
}