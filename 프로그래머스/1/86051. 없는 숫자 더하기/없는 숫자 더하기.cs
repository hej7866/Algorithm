using System;

public class Solution 
{
    public int solution(int[] numbers) 
    {
        int ans = 0;
        for(int i=0; i<=9; i++)
        {
            bool isBool = false;
            foreach(int num in numbers)
            {
                if(i == num)
                {
                    isBool = true;
                }
            }
            if(!isBool)
            {
                ans += i;
            }
        }
        return ans;
    }
}