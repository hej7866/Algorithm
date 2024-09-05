using System;

public class Solution 
{
    public int solution(string[] order) 
    {     
        int americanoCount = 0;
        int cafelatteCount = 0;
        for(int i=0; i<order.Length; i++)
        {
            if(order[i].Contains("americano") || order[i].Contains("anything"))
            {
                americanoCount++; 
            }
            else if(order[i].Contains("cafelatte"))
            {
                cafelatteCount++;
            }
        }
        return americanoCount * 4500 + cafelatteCount * 5000;
    }
}