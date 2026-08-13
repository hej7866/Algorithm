using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(string[] keymap, string[] targets) 
    {
        Dictionary<char, int> minPress = new Dictionary<char, int>();
        
        foreach(string key in keymap)
        {
            for (int i = 0; i < key.Length; i++)
            {
                char c = key[i];
                int press = i + 1;  // i번째 위치니까 (i+1)번 눌러야 함
                
                if (!minPress.ContainsKey(c) || minPress[c] > press)
                {
                    minPress[c] = press;  // 더 적은 횟수로 갱신
                }
            }
        }
        
        int[] result = new int[targets.Length];
        
        for(int i=0; i<targets.Length; i++)
        {
            int total = 0;
            bool possible = true;
            foreach(char c in targets[i])
            {
                if(!minPress.ContainsKey(c))
                {
                    possible = false;
                    break;
                }
                total += minPress[c];
            }
            result[i] = possible ? total : -1;
        }
        return result;
    }
}