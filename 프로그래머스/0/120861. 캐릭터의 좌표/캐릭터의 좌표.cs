using System;

public class Solution 
{
    public int[] solution(string[] keyinput, int[] board) 
    {
        int[] playerPos = {0,0}; // 플레이어 좌표의 초기값 입력
        
        int boundaryLeft  = -((board[0] - 1) / 2); // board의 경계선 할당 (왼쪽)
        int boundaryRight =  ((board[0] - 1) / 2); // board의 경계선 할당 (오른쪽)
        int boundaryUp    =  ((board[1] - 1) / 2); // board의 경계선 할당 (위쪽)
        int boundaryDown  = -((board[1] - 1) / 2); // board의 경계선 할당 (아래쪽)
        for(int i=0; i<keyinput.Length; i++)
        {
            switch (keyinput[i])
            {
                case "left":
                    if(playerPos[0] == boundaryLeft)  // 만약 현재 위치가 왼쪽 경계선과 같다면 반복문으로돌아가라
                    {
                        continue;
                    }
                    playerPos[0]--;
                    break;
                case "right":
                    if(playerPos[0] == boundaryRight)  // 만약 현재 위치가 오른쪽 경계선과 같다면 반복문으로돌아가라
                    {
                        continue;
                    }
                    playerPos[0]++;
                    break;
                case "up":
                    if(playerPos[1] == boundaryUp)  // 만약 현재 위치가 위쪽 경계선과 같다면 반복문으로돌아가라
                    {
                        continue;
                    }
                    playerPos[1]++;
                    break;
                case "down":
                    if(playerPos[1] == boundaryDown)  // 만약 현재 위치가 아래쪽 경계선과 같다면 반복문으로돌아가라
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