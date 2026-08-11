using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long p = price;
        long m = money;
        for(int i=1; i<=count; i++)
        {
            m -= p * i;
        }
        return m > 0 ? 0 : m * (-1);
    }
}