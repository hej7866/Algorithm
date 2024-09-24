using System;

public class Solution 
{
    public string solution(int[] food) 
    {
        string str1 = "";
        string str2 = "";
        for(int i=1; i<food.Length; i++)
        {
            int f = food[i] / 2;
            for(int j=0; j<f; j++)
            {
                str1 += i.ToString();
            }
        }
        for(int i=food.Length - 1; i>=1; i--)
        {
            int f = food[i] / 2;
            for(int j=0; j<f; j++)
            {
                str2 += i.ToString();
            }
        }
        return str1 + "0" + str2;
    }
}