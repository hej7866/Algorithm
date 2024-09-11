#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) 
{
    int d1 = 0;
    int d2 = 0;

    for(int i=0; i<bin1.size(); i++)
    {
        if(bin1[i] == '1')
        {
            d1 += (1 << bin1.size() - 1 - i);
        }
    }
    
    for(int i=0; i<bin2.size(); i++)
    {
        if(bin2[i] == '1')
        {
            d2 += (1 << bin2.size() - i - 1);
        }
    }
    
    string result = "";
    int sum = d1 + d2;
    cout << sum;
    if(sum == 0)
    {
        result = "0";
    }
    else
    {    
        while(sum > 0)
        {
            result += (sum%2 == 0) ? '0' : '1';
            sum /= 2;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}