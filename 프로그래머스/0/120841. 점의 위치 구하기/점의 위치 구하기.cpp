#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) 
{
    int x = dot[0];
    int y = dot[1];
    
    if(x>0)
    {
        if(y>0)
        {
            return 1;
        }
        else if(y<0)
        {
            return 4;
        }
    }
    else if(x<0)
    {
        if(y>0)
        {
            return 2;
        }
        else if(y<0)
        {
            return 3;
        }
    }
}