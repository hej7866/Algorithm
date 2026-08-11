using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string[] survey, int[] choices) 
    {
        // R T , C F, J M, A N
        Dictionary<char, int> pointDic = new Dictionary<char, int>()
        {
            {'R', 0}, {'T', 0}, 
            {'C', 0}, {'F', 0},
            {'J', 0}, {'M', 0}, 
            {'A', 0}, {'N', 0}
        };
        
        for(int i=0; i<survey.Length; i++)
        {
            if(choices[i] < 4)
            {
                pointDic[survey[i][0]] += 4 - choices[i];
            }
            else if(choices[i] > 4)
            {
                pointDic[survey[i][1]] += choices[i] - 4;
            }
        } 
        
        string result = "";
        if(pointDic['R'] >= pointDic['T'])
        {
            result += 'R';
        }
        else
        {
            result += 'T';
        }
        
        if(pointDic['C'] >= pointDic['F'])
        {
            result += 'C';
        }
        else
        {
            result += 'F';
        }
        
        if(pointDic['J'] >= pointDic['M'])
        {
            result += 'J';
        }
        else
        {
            result += 'M';
        }
        
        if(pointDic['A'] >= pointDic['N'])
        {
            result += 'A';
        }
        else
        {
            result += 'N';
        }
        return result;
    }
}