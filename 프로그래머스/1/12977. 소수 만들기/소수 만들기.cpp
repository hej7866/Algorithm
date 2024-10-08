#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums) 
{
    auto sumThreeElements = [](const vector<int>& nums, int a, int b, int c) 
    {
        return nums[a] + nums[b] + nums[c];
    };

    int count = 0;
    // 모든 조합을 위한 중첩 반복문
    for (int i = 0; i < nums.size(); i++) 
    {
        for (int j = i + 1; j < nums.size(); j++) 
        {
            for (int k = j + 1; k < nums.size(); k++) 
            {
                int sum = sumThreeElements(nums, i, j, k); // 람다 호출
                
                bool isBool = false;
                for(int i=2; i<sum; i++)
                {
                    if(sum%i == 0)
                    {
                        isBool = true;
                    }
                }
                if(!isBool)
                {
                    count++;
                }
            }
        }
    }
    return count;
}