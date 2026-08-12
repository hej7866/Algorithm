using System;
using System.Text;

public class Solution 
{
    public string solution(int[] food) 
    {
        StringBuilder tmp = new StringBuilder();
        for(int i=1; i<food.Length; i++)
        {
            int count = food[i] / 2;
            for(int j=0; j<count; j++)
            {
                tmp.Append(i.ToString());
            }
        }
        char[] chars = tmp.ToString().ToCharArray();
        Array.Reverse(chars);
        string reversed = new string(chars);
        tmp.Append("0");
        tmp.Append(reversed);
        
        return tmp.ToString();
    }
}