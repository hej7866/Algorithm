using System;
using System.Text;

public class Solution 
{
    public int solution(string message, int[,] spoiler_ranges) 
    {
        int count = spoiler_ranges.GetLength(0);
        
        // 비밀구절 만들기
        StringBuilder secretMessage = new StringBuilder(message);
        for(int i=0; i<count; i++)
        {
            for(int j=spoiler_ranges[i,0]; j<=spoiler_ranges[i,1]; j++)
            {
                if(secretMessage[j] != ' ')
                {
                    secretMessage[j] = '*';
                }
            }
        }
        int result = 0;
      
        string[] secretSplit = secretMessage.ToString().Split(' ');
        string[] split = message.Split(' ');

        for(int i=0; i<secretSplit.Length; i++)
        {
            if(secretSplit[i].Contains('*'))
            {
                if(!secretSplit.Contains(split[i]))
                {
                    Console.WriteLine(split[i]);
                    result++;
                }
                secretSplit[i] = split[i];
            }
        }
        return result;
    }
}