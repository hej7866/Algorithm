using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string myStr) 
    {   
        char[] delimiters = { 'a', 'b', 'c', };
        string[] parts = myStr.Split(delimiters, StringSplitOptions.RemoveEmptyEntries);
        List<string> partsList = new List<string>(parts);
        
        if(partsList.Count == 0) {
            partsList.Add("EMPTY");
        }
        
        parts = partsList.ToArray();
        return parts;
    }
}