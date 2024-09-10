#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    int count = 1;
    string result = "";
    for(char &c : cipher)
    {
        if(count%code == 0)
        {
            result += c;
        }
        count++;
    }
    return result;
}