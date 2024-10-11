using System;

public class Solution 
{
    public int solution(int n) 
    {
        string s = n.ToString();
        int sum = 0;
        foreach(char c in s)
        {
            sum += c - '0';
        }
        return sum;
    }
}