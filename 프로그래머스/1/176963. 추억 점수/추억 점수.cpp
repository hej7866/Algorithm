#include <string>
#include <vector>
#include <map>


using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    map<string, int> nameMap;
    for(int i=0; i<name.size(); i++)
    {
        nameMap[name[i]] = yearning[i];
    }
    
    vector<int> pointVec;
    for(auto &v : photo)
    {
        int point = 0;
        for(string &s : v)
        {
            point += nameMap[s];
        }
        pointVec.push_back(point);
    }
    return pointVec;
}