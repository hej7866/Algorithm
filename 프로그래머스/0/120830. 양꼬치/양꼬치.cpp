#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) 
{
    int s = n/10;
    return 12000 * n + (k - s) * 2000;
}