using System;
using System.Collections.Generic;

class Solution
{
    public int[] solution(int n, string[] words)
    {
        List<string> wordList = new List<string>();
        int[] result = new int[2];
        for(int i=0; i<words.Length; i++)
        {    
            if(!wordList.Contains(words[i]))
            {
                wordList.Add(words[i]);
            }
            else
            {
                result[0] = i % n + 1;
                result[1] = i / n + 1;
                break;
            }
            
            if(i >= 1)
            {
                if(words[i][0] != words[i - 1][words[i - 1].Length - 1])
                {
                    result[0] = i % n + 1;
                    result[1] = i / n + 1;
                    break;
                }
            }
        }
        return result;
    }
}