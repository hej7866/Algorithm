#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) 
{
    vector<int> alphabet(52,0);
    
    for(char &ch : my_string)
    {
        if(ch >= 65 && ch <= 90)
        {
            alphabet[ch-65]++;
        }
        else if(ch >= 97 && ch <= 122)
        {
            alphabet[ch-71]++;
        }
    }
    return alphabet;
}