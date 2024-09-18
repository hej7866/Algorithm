#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) 
{
    vector<int> vec(2,0);
    vec[0] = (numer1 * denom2) + (numer2 * denom1);
    vec[1] = denom1 * denom2;
    
    int i = 2;
    while(i<= vec[0] && i<= vec[1])
    {
        while(vec[0]%i == 0 && vec[1]%i ==0)
        {
            vec[0] /= i;
            vec[1] /= i;
        }
        i++;
    }
    cout << vec[0] << "," << vec[1];
    return vec;
}