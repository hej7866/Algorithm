#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for(int a : A)
    {
        cout << a << " ";
    }
    cout << "\n";
    for(int b : B)
    {
        cout << b << " ";
    }

    int result = 0;
    for(int i = 0; i<A.size(); i++)
    {
        result += A[i] * B[i];   
    }
    

    return result;
}