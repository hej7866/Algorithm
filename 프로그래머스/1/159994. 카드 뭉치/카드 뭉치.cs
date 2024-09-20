using System;
using System.Collections.Generic;

public class Solution 
{
    public string solution(string[] cards1, string[] cards2, string[] goal) 
    {
        Dictionary<string, int> cardsDic1 = new Dictionary<string, int>();
        Dictionary<string, int> cardsDic2 = new Dictionary<string, int>();
        
        for(int i=0; i<cards1.Length; i++) { cardsDic1[cards1[i]] = i; }
        for(int i=0; i<cards2.Length; i++) { cardsDic2[cards2[i]] = i; }
        
        List<int> indexC1 = new List<int>();
        List<int> indexC2 = new List<int>();
        foreach(string g in goal)
        {
            if(cardsDic1.ContainsKey(g))
            {
                indexC1.Add(cardsDic1[g]);
            }
            else if(cardsDic2.ContainsKey(g))
            {
                indexC2.Add(cardsDic2[g]);
            }
        }
        
        bool isBool = false;
        for(int i=0; i<indexC1.Count; i++)
        {
            if(indexC1[i] != i) { isBool = true; }
        }
        
        for(int i=0; i<indexC2.Count; i++)
        {
            if(indexC2[i] != i) { isBool = true; }
        }
        return isBool ? "No" : "Yes";
    }
}