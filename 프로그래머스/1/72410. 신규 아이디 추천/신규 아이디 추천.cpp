#include <string>
#include <vector>
#include <iostream>
#include <regex>

using namespace std;

string solution(string new_id) 
{
    // #1.
    for(char &c : new_id)
    {
        if(isupper(c))
        {
            c = tolower(c);
        }
    }
    cout << new_id << "\n";
    
    // #2.
    string tmp = "";
    for(char &c : new_id)
    {
        if(islower(c) || isdigit(c) || c == '-' || c == '_' || c == '.')
        {
            tmp += c;
        }
    }
    new_id = tmp;
    cout << new_id << "\n";
    
    // #3.
    new_id = regex_replace(new_id, regex("\\.+"), ".");
    
    // #4.
    if (!new_id.empty() && new_id.front() == '.') 
    {
        new_id.erase(new_id.begin());
    }
    if (!new_id.empty() && new_id.back() == '.') 
    {
        new_id.pop_back();
    }

    cout << new_id << "\n";
    
    // #5.
    if(new_id.empty())
    {
        new_id = "a";
    }
    cout << new_id << "\n";
    
    // #6.
    if (new_id.size() > 15) 
    {
        new_id = new_id.substr(0, 15);
        if (new_id.back() == '.') 
        {
            new_id.pop_back();
        }
    }
    cout << new_id << "\n";

    
    // #7.
    if(new_id.length() <= 2)
    {
        char t = new_id[new_id.length() - 1];
        while(new_id.length() < 3)
        {
            new_id += t;
        }
    }
    cout << new_id << "\n";
    
    return new_id;
}