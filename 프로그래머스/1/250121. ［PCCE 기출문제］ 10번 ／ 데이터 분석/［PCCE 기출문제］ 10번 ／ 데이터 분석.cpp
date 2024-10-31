#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<string> dataString = 
    {
        {"code", "date", "maximum", "remain"}
    };
    
    int idx = 0; 
    for(int i=0; i<dataString.size(); i++)
    {
        if(dataString[i] == ext) 
        { 
            idx = i;
            break;
        };
    }
    
    vector<vector<int>> sortData;
    for(int i=0; i<data.size(); i++)
    {
        if(data[i][idx] < val_ext)
        {
            sortData.push_back(data[i]);
        }
    }
    
    int idx2;
    for(int i=0; i<dataString.size(); i++)
    {
        if(dataString[i] == sort_by) 
        { 
            idx2 = i;
            break;
        }
    }
    if(idx2 == 0)
    {
        sort(sortData.begin(), sortData.end(), [] (const vector<int> a, const vector<int> b) {
        return a[0] < b[0];
        });
    }
    else if(idx2 == 1)
    {
        sort(sortData.begin(), sortData.end(), [] (const vector<int> a, const vector<int> b) {
        return a[1] < b[1];
        });
    }
    else if(idx2 == 2)
    {
        sort(sortData.begin(), sortData.end(), [] (const vector<int> a, const vector<int> b) {
        return a[2] < b[2];
        });
    }
    else if(idx2 == 3)
    {
        sort(sortData.begin(), sortData.end(), [] (const vector<int> a, const vector<int> b) {
        return a[3] < b[3];
        });
    }
    
    return sortData;
}