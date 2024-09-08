#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> picture, int k) 
{
    vector<string> vec;
    for(int i=0; i<picture.size(); i++)
    {
        string temp = picture[i];
        string s = "";
        for(int j=0; j<temp.length(); j++)
        {
            for(int w=0; w<k; w++) { s += temp[j]; }
        }
        for(int g=0; g<k; g++) { vec.push_back(s); }
    }
    return vec;
}