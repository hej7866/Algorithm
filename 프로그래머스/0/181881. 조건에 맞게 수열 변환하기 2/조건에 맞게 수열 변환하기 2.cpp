#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> arr) 
{
    int count = 0;
    vector<int> tmp;
    while(tmp != arr)
    {
        count++;
        tmp = arr;
        for(int &n : arr)
        {
            if(n >= 50 && n%2 == 0)
            {
                n /= 2;
            }
            else if (n < 50 && n%2 == 1)
            {
                n *= 2;
                n += 1;
            }
        }
    }
    return count - 1;
}