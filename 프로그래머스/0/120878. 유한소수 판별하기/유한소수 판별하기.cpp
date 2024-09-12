#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 1;
int solution(int a, int b) 
{
    int i = 2;
    while(i<=a || i<= b)
    {
        while(a%i == 0 && b%i == 0)
        {
            a /= i;
            b /= i;
        }
        i++;
    }
    
    vector<int> division;
    int j=2;
    while(j<=b)
    {
        while(b%j == 0)
        {
            b /= j;
            division.push_back(j);
        }
        j++;
    }
    
    for(int &d : division)
    {
        if(d != 2 && d != 5)
        {
            answer = 2;
        }
        cout << d << " ";
    }
    return answer;
}