using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(string s) 
    {
        int count = 0;
        int zeroCount = 0;
        List<char> charList = s.ToList();
        
        while(charList.Count > 1)
        { 
            for(int i=charList.Count-1; i>=0; i--)
            {
                if(charList[i] == '0')
                {
                    charList.RemoveAt(i);
                    zeroCount++;
                }
            }
            
            int length = charList.Count;
            string newS = "";
            while(length > 0)
            {
                newS += (length % 2).ToString();
                length /= 2;
            }
            string reversed = new string(newS.Reverse().ToArray());
            Console.WriteLine(reversed);
            charList = reversed.ToList();
            count++;
        }
        return new int[] {count, zeroCount};
    }
}