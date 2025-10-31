#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) 
{
    int size1 = my_string.size();
    int size2 = is_suffix.size();
    int pos = size1 - size2;
    
    if(pos < 0) return 0;
    
    if(my_string.substr(pos,size2) == is_suffix)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}