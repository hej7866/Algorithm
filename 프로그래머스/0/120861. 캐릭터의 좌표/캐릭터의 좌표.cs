using System;

public class Solution 
{
    public int[] solution(string[] keyinput, int[] board) 
    {
        int[] playerPos = {0,0};
        
        int boundaryLeft  = -((board[0] - 1) / 2);
        int boundaryRight =  ((board[0] - 1) / 2);
        int boundaryUp    =  ((board[1] - 1) / 2);
        int boundaryDown  = -((board[1] - 1) / 2);
        for(int i=0; i<keyinput.Length; i++)
        {
            switch (keyinput[i])
            {
                case "left":
                    if(playerPos[0] == boundaryLeft) 
                    {
                        continue;
                    }
                    playerPos[0]--;
                    break;
                case "right":
                    if(playerPos[0] == boundaryRight) 
                    {
                        continue;
                    }
                    playerPos[0]++;
                    break;
                case "up":
                    if(playerPos[1] == boundaryUp) 
                    {
                        continue;
                    }
                    playerPos[1]++;
                    break;
                case "down":
                    if(playerPos[1] == boundaryDown) 
                    {
                        continue;
                    }
                    playerPos[1]--;
                    break;                   
            }
        }
        
        return playerPos;
    }
}