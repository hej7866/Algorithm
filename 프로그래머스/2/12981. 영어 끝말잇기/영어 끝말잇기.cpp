#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    vector<int> result(2); 
    
    vector<vector<string>> vec(n+1);
    vector<string> w;
    for(int i=0; i<words.size(); i++)
    {
        if(i >= 1 && words[i-1][words[i-1].size()-1] != words[i][0])
        {
            cout << 1;
            int tmp = (i+1) % n;
            if(tmp != 0)
            {
                vec[tmp].push_back(words[i]);
                result[0] = tmp;
                result[1] = vec[tmp].size(); 
            }
            else
            {
                vec[n].push_back(words[i]);
                result[0] = n;
                result[1] = vec[n].size(); 
            }
            break;
        } 
        else if(find(w.begin(), w.end(), words[i]) == w.end()) 
        {            
            int tmp = (i+1) % n;
            if(tmp != 0)
            {
                vec[tmp].push_back(words[i]);
            }
            else
            {
                vec[n].push_back(words[i]);
            }
        }
        else if(find(w.begin(), w.end(), words[i]) != w.end())
        {
            int tmp = (i+1) % n;
            if(tmp != 0)
            {
                vec[tmp].push_back(words[i]);
                result[0] = tmp;
                result[1] = vec[tmp].size(); 
            }
            else
            {
                vec[n].push_back(words[i]);
                result[0] = n;
                result[1] = vec[n].size(); 
            }
            break;
        }
        w.push_back(words[i]);
    }

    
    return result;
}