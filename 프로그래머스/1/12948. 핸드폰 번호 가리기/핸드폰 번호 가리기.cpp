#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) 
{
    string star = "";
    for(int i=0; i<phone_number.length() - 4; i++)
    {
        star += "*";
    }
    phone_number.replace(0,phone_number.length() - 4,star);
    
    return phone_number;
}