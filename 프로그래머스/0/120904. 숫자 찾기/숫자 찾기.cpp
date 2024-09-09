#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int num, int k) 
{
    string numStr = to_string(num);
    
    size_t pos = numStr.find(to_string(k));
    if(pos == string::npos)
    {
        return -1;
    }
    else
    {    
        return pos+1;
    }
}