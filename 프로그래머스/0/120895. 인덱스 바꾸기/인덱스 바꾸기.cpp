#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) 
{
    char tmp1 = my_string[num1];
    char tmp2 = my_string[num2];
    
    my_string[num1] = tmp2;
    my_string[num2] = tmp1;
    
    return my_string;
}