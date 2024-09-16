#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int balls, int share) 
{
    long double n = 1;
    for(int i=share + 1; i<=balls; i++)
    {
        n *= i;
    }
    for(int i=1; i<=balls - share; i++)
    {
        n /= i;
    }
    cout << n << endl;
    return n;
}