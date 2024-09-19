#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    map<char, int> touchmap;
    for(int i=0; i<keymap.size(); i++)
    {
        for(int j=0; j<keymap[i].size(); j++)
        {
            char c = keymap[i][j];
            
            if(touchmap.find(c) != touchmap.end())
            {
                touchmap[c] = min(touchmap[c], j + 1);
            }
            else
            {
                touchmap[c] = j + 1;
            }
        }
    }
    
    vector<int> result;
    for(string &target : targets)
    {
        int touchCount = 0;
        for(char &ch : target)
        {
            if(touchmap.find(ch) != touchmap.end())
            {
                touchCount += touchmap[ch];
            }
            else
            {
                touchCount = -1;
                break;
            }
        }
        result.push_back(touchCount);
    }
    return result;
}