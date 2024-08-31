using System;

public class Solution 
{
    public int solution(int price)
    {
        double priceD = price;
        if(price >= 100000 && price < 300000)
        {
            priceD = price * 0.95;
        }
        else if(price >= 300000 && price < 500000)
        {
            priceD = price * 0.9;
        }
        else if(price >= 500000)
        {
            priceD = price * 0.8;
        }
        return (int)priceD;
    }
}