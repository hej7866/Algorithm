#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) 
{
    int i = 0;
    while(i < arr.size())
    {   
        bool isCheck = false;
        for(int &num : delete_list)
        {
            if(arr[i] == num)
            {
                arr.erase(arr.begin()+i);
                isCheck = true;
            }
        }
        if(isCheck)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
    return arr;
}