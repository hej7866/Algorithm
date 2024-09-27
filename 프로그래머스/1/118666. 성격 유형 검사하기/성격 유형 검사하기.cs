using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string[] survey, int[] choices) 
    {
        char[,] mbtiArr = new char[4,2]
        {
            {'R', 'T'},
            {'C', 'F'},
            {'J', 'M'},
            {'A', 'N'},
        };
        
        Dictionary<char, int> score = new Dictionary<char, int>();
        for(int i = 0; i < mbtiArr.GetLength(0); i++)
        {
            score[mbtiArr[i, 0]] = 0;
            score[mbtiArr[i, 1]] = 0;
        }
        
        for(int i = 0; i < survey.Length; i++)
        {
            if(choices[i] < 4)
            {
                score[survey[i][0]] += (4 - choices[i]);
            } 
            else
            {
                score[survey[i][1]] += (choices[i] - 4); 
            }
        }
        
        string ans = "";
        for(int i = 0; i < 4; i++)
        {
            if(score[mbtiArr[i,0]] >= score[mbtiArr[i,1]]) { ans += mbtiArr[i,0]; }
            else { ans += mbtiArr[i,1]; }
        }
        return ans;
    }
}