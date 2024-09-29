#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int wMax = 0;
    int hMax = 0;
    for(int i=0; i<sizes.size(); i++)
    {
        int w = sizes[i][0];
        int h = sizes[i][1];

        if(wMax < w)
        {
            wMax = w;
        }
        if(hMax < h)
        {
            hMax = h;
        }
    }

    int max = (wMax > hMax) ? wMax : hMax;

    vector<int> ans(2,0);
    ans[0] = max;

    for(int i=0; i<sizes.size(); i++)
    {
        int w = sizes[i][0];
        int h = sizes[i][1];

        int tmp = (w > h) ? h : w;
        if(ans[1] < tmp)
        {             
            ans[1] = tmp;
        }
    }
    int area = 1;
    for(int &num : ans)
    {
        area *= num;
    }

    return area;
}