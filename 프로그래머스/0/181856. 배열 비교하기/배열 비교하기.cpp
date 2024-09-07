#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) 
{
    int answer = 0;
    int arr1Sum = 0;
    int arr2Sum = 0;
    if(arr1.size() != arr2.size())
    {
        if(arr1.size() > arr2.size()) {answer = 1;}
        else {answer = -1;}
    }
    else
    {
        for(int &num : arr1)
        {
            arr1Sum += num;
        }
        for(int &num : arr2)
        {
            arr2Sum += num;
        }
        if(arr1Sum > arr2Sum) {answer = 1;}
        else if(arr1Sum < arr2Sum) {answer = -1;}
        else {answer = 0;}
    }
    return answer;
}