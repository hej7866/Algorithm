using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string[] want, int[] number, string[] discount) 
    {
        // 사전에 등록
        Dictionary<string, int> wantDic = new Dictionary<string, int>();
        for(int i=0; i<want.Length; i++)
        {
            wantDic[want[i]] = number[i];
        }
        
        int count = 0;
        for(int i=0; i<=discount.Length - 10; i++)
        {
            Dictionary<string, int> copy = new Dictionary<string, int>(wantDic);
            for(int j=i; j<i+10; j++)
            {
                if(!copy.ContainsKey(discount[j]))
                {
                    continue;
                }
                copy[discount[j]]--;
            }
            
            bool b = true;
            foreach(var v in copy)
            {
                if(v.Value != 0)
                {
                    b = false;
                    break;
                }
            }
            
            if(b)
            {
                count++;
            }
        }
        return count;
    }
}