using System;

public class Solution 
{
    public int solution(int[,] board) 
    {
        int boardH = board.GetLength(0); // board의 가로길이
        int boardV = board.GetLength(1); // board의 세로길이
        
        int count = 0;
        for(int i=0; i<boardH; i++)
        {
            for(int j=0; j<boardV; j++)
            {
                if(board[i,j] == 1) 
                {
                    count++;
                }
            }
        }
        
        int[,] boomPos = new int[count,2];
        int index = 0;
        for(int i=0; i<boardH; i++)
        {
            for(int j=0; j<boardV; j++)
            {
                if(board[i,j] == 1) 
                {
                    boomPos[index,0] = i;
                    boomPos[index,1] = j;
                    index++;
                }
            }
        }
        
        
        int[,] boardX = new int[boardH, boardV];
        Array.Copy(board, boardX, board.Length); // 깊은복사
        
        int bpRow = boomPos.GetLength(0);
        for(int i=0; i<bpRow; i++)
        {
            int j = boomPos[i,0]; // 3
            int k = boomPos[i,1]; // 2
            for(int dj = -1; dj <= 1; dj++)
            {
                for(int dk = -1; dk <= 1; dk++)
                {
                    if (dj == 0 && dk == 0) continue; // 중심점은 무시

                    int newJ = j + dj;
                    int newK = k + dk;

                    // 배열 범위 확인
                    if (newJ >= 0 && newJ < boardH && newK >= 0 && newK < boardV)
                    {
                        boardX[newJ, newK] = 2;
                    }
                }
            }
        }
        
        int zeroCount = 0;
        for(int i = 0; i < boardX.GetLength(0); i++)
        {
            for(int j = 0; j < boardX.GetLength(1); j++)    
            {
                if(boardX[i,j] == 0)
                {
                   zeroCount++; 
                }
            }
        }
        return zeroCount;
    }
} 
        
        // for(int i=0; i<bpRow; i++)
        // {           
        //     int j = boomPos[i,0]; // 3
        //     int k = boomPos[i,1]; // 2
        //     if(j > 0 && j < boardH - 1) 
        //     {
        //         if(k > 0 && k < boardV - 1) 
        //         {
        //             boardX[j-1,k-1] = 2;
        //             boardX[j-1,k] = 2;  
        //             boardX[j-1,k+1] = 2;  
        //             boardX[j,k-1] = 2;  
        //             boardX[j,k+1] = 2;  
        //             boardX[j+1,k-1] = 2;  
        //             boardX[j+1,k] = 2;  
        //             boardX[j+1,k+1] = 2;  
        //         }
        //         else if(k == 0) 
        //         {
        //             boardX[j-1,k] = 2;  
        //             boardX[j-1,k+1] = 2;  
        //             boardX[j,k+1] = 2;  
        //             boardX[j+1,k] = 2;  
        //             boardX[j+1,k+1] = 2;  
        //         }
        //         else if(k == boardV - 1) 
        //         {
        //             boardX[j-1,k-1] = 2;
        //             boardX[j-1,k] = 2;   
        //             boardX[j,k-1] = 2;   
        //             boardX[j+1,k-1] = 2;  
        //             boardX[j+1,k] = 2;  
        //         }
        //     }
        //     else if(j == 0) 
        //     {
        //         if(k > 0 && k < boardV - 1) 
        //         {
        //             boardX[j,k-1] = 2;  
        //             boardX[j,k+1] = 2;  
        //             boardX[j+1,k-1] = 2;  
        //             boardX[j+1,k] = 2;  
        //             boardX[j+1,k+1] = 2;  
        //         }
        //         else if(k == 0) 
        //         {
        //             boardX[j,k+1] = 2;  
        //             boardX[j+1,k] = 2;  
        //             boardX[j+1,k+1] = 2;  
        //         }
        //         else if(k == boardV - 1) 
        //         { 
        //             boardX[j,k-1] = 2;   
        //             boardX[j+1,k-1] = 2;  
        //             boardX[j+1,k] = 2;  
        //         }
        //     }
        //     else if(j == boardH - 1) 
        //     {
        //         if(k > 0 && k < boardV - 1) 
        //         {
        //             boardX[j-1,k-1] = 2;
        //             boardX[j-1,k] = 2;  
        //             boardX[j-1,k+1] = 2;  
        //             boardX[j,k-1] = 2;  
        //             boardX[j,k+1] = 2;  
        //         }
        //         else if(k == 0) 
        //         {
        //             boardX[j-1,k] = 2;  
        //             boardX[j-1,k+1] = 2;  
        //             boardX[j,k+1] = 2;   
        //         }
        //         else if(k == boardV - 1) 
        //         {
        //             boardX[j-1,k-1] = 2;
        //             boardX[j-1,k] = 2;   
        //             boardX[j,k-1] = 2;   
        //         }
        //     }
        // }