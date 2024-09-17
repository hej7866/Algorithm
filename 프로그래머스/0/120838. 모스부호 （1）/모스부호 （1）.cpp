#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string letter) 
{
    map<string, string> morse = 
    {
        {".-","a"},{"-...", "b"},{"-.-.","c"},{"-..","d"},{".","e"},{"..-.","f"},
        {"--.","g"},{"....","h"},{"..","i"},{".---","j"},{"-.-","k"},{".-..","l"},
        {"--","m"},{"-.","n"},{"---","o"},{".--.","p"},{"--.-","q"},{".-.","r"},
        {"...","s"},{"-","t"},{"..-","u"},{"...-","v"},{".--","w"},{"-..-","x"},
        {"-.--","y"},{"--..","z"}
    };
    
    string str = "";
    string result = "";
    for(char &c : letter)
    {
        if(c != ' ')
        {
            str +=c;
        }
        else if(c == ' ')
        {
            result += morse[str];
            str = "";
        }
    }
    if(!str.empty())
    {
        result += morse[str];
    }
    return result;
}