using System;

public class Solution 
{
    public int solution(string s) 
    {
        string[] ctrlZ = new string[s.Length];
        ctrlZ = s.Split(" ");
        
        int numSum = 0;
        
        for(int i=0; i<ctrlZ.Length; i++)
        {
            if(ctrlZ[i].ToString() != "Z")
            {
                numSum += Int32.Parse(ctrlZ[i].ToString());
            }
            else
            {
                numSum -= Int32.Parse(ctrlZ[i-1].ToString());
            }
        }
        return numSum;
    }
}