using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long sum = 0;
        for(int i=1; i<=count; i++)
        {
            sum += price * i;
        }
        long ans = 0;
        if(sum > money)
        {
            ans = sum - money;
        }
        else
        {
            ans = 0;
        }
        return ans;
    }
}