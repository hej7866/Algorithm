#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    map<string, int> cardsMap1;
    map<string, int> cardsMap2;
    
    for(int i=0; i<cards1.size(); i++) { cardsMap1[cards1[i]] = i; }
    for(int i=0; i<cards2.size(); i++) { cardsMap2[cards2[i]] = i; }
    
    vector<int> idxVec1;
    vector<int> idxVec2;
    
    for(string &g : goal)
    {
        if(cardsMap1.find(g) != cardsMap1.end())
        {
            idxVec1.push_back(cardsMap1[g]);
        }
        else if(cardsMap2.find(g) != cardsMap2.end())
        {
            idxVec2.push_back(cardsMap2[g]);
        }
    }
    
    string result = "Yes";
    for(int i=0; i<idxVec1.size(); i++)
    {
        if(idxVec1[i] != i)
        {
            result =  "No";
        }
    }
    for(int i=0; i<idxVec2.size(); i++)
    {
        if(idxVec2[i] != i)
        {
            result = "No";
        }
    }
    return result;
}