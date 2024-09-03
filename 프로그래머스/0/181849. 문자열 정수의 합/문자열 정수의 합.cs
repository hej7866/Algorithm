using System;

public class Solution 
{
    public int solution(string num_str) 
    {
        int numSum = 0;
        for(int i=0; i<num_str.Length; i++)
        {
            numSum += Int32.Parse(num_str[i].ToString());
        }
        return numSum;
    }
}