using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(int[] answers) 
    {
        int[] f = new int[] {1, 2, 3, 4, 5};
        int[] s = new int[] {2, 1, 2, 3, 2, 4, 2, 5};
        int[] t = new int[] {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
        
        int[] scores = new int[3];
        for(int i=0; i<answers.Length; i++)
        {
            if(f[i%5] == answers[i])
            {
                scores[0]++;
            }
            if(s[i%8] == answers[i])
            {
                scores[1]++;
            }
            if(t[i%10] == answers[i])
            {
                scores[2]++;
            }
        }
        
        int max = scores.Max();
        
        List<int> result = new List<int>();
        for(int i = 0; i < 3; i++)
        {
            if(scores[i] == max)
            {
                result.Add(i + 1);
            }
        }
        
        return result.ToArray();
        
    }
}