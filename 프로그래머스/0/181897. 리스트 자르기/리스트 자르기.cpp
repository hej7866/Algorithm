#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) 
{
    vector<int> v;
    switch(n)
    {
        case 1:
            for(int i=0; i<=slicer[1]; i++)
            {
                v.push_back(num_list[i]);
            }
            break;
        case 2:
            for(int i=slicer[0]; i<num_list.size(); i++)
            {
                v.push_back(num_list[i]);
            }
            break;
        case 3:
            for(int i=slicer[0]; i<=slicer[1]; i++)
            {
                v.push_back(num_list[i]);
            }
            break;
        case 4:
            for(int i=slicer[0]; i<=slicer[1]; i += slicer[2])
            {
                v.push_back(num_list[i]);
            }
            break;
    }
    return v;
}