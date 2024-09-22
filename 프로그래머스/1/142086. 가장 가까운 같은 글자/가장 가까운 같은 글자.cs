using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(string s) 
    {
        int[] indexArr = new int[s.Length];
        
        for(int i=0; i<s.Length; i++)
        {
            int currIdx = i;
            for(int j=0; j<currIdx; j++)
            {
                if(s[j] == s[i]) { indexArr[i] = i-j; }
            }
        }
        
        for(int i=0; i<indexArr.Length; i++)
        {
            if(indexArr[i] == 0) { indexArr[i] = -1; }
        }
        return indexArr;
    }
}