#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) 
{
    int count = 0;
    while(true)
    {      
        bool isCheck = false;
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i] >= 50 && arr[i]%2 == 0)
            {
                arr[i] /= 2;
                isCheck = true;
            }
            else if(arr[i] < 50 && arr[i]%2 == 1)
            {
                arr[i] *= 2;
                arr[i] += 1;
                isCheck = true;
            }
        }
        if(!isCheck)
        {
            break;
        }
        count++;
    }
    return count;
}