using System;
using System.Collections.Generic;

public class Solution 
{
    public string[] solution(string[] players, string[] callings) 
    {
        Dictionary<string, int> playerIndex = new Dictionary<string, int>();
        for (int i = 0; i < players.Length; i++)
        {
            playerIndex[players[i]] = i;
        }
        foreach (string call in callings)
        {
            int currentIndex = playerIndex[call];
            if (playerIndex.ContainsKey(call))
            {
                string previousPlayer = players[currentIndex - 1];
                
                players[currentIndex - 1] = players[currentIndex];
                players[currentIndex] = previousPlayer;
                
                playerIndex[call] = currentIndex - 1;
                playerIndex[previousPlayer] = currentIndex;
            }
        }
        return players;
    }
}