using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string[] players, string[] callings) 
    {
        Dictionary<string, int> playersDic = new Dictionary<string, int>();
        for(int i=0; i<players.Length; i++)
        {
            playersDic[players[i]] = i;
        }
        
        foreach(string calling in callings)
        {
            int idx = playersDic[calling];
            int prevIdx = idx - 1;
            string prevName = players[prevIdx];
            
            players[idx] = prevName;
            players[prevIdx] = calling;
            
            playersDic[calling] = prevIdx;
            playersDic[prevName] = idx;
        }
        
        return players;
    }
}