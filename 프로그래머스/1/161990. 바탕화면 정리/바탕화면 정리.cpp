#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> wallpaper) 
{   
    vector<int> rowVec;
    vector<int> colVec;
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j=0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                rowVec.push_back(i);
                colVec.push_back(j);
            }
        }
    }
    sort(rowVec.begin(), rowVec.end());
    sort(colVec.begin(), colVec.end());
    
    int up = rowVec.front();
    int left = colVec.front();
    int right = colVec.back();
    int down = rowVec.back();

    vector<int> answer = {up,left,down+1,right+1};
    for(int &i : answer)
    {
        cout << i << " ";
    }
    return answer;
}