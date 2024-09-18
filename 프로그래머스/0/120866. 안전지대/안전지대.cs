using System;

public class Solution 
{
    public int solution(int[,] board) 
    {
        int boardH = board.GetLength(0); // board의 가로길이
        int boardV = board.GetLength(1); // board의 세로길이
        
        int count = 0; // 폭탄의 갯수를 카운트하기위한 변수
        for(int i=0; i<boardH; i++)
        {
            for(int j=0; j<boardV; j++)
            {
                if(board[i,j] == 1)  // i,j위치에 폭탄이있다면 count를 하나 늘린다.
                {
                    count++;
                }
            }
        }
        
        int[,] boomPos = new int[count,2]; // 폭탄의위치를 좌표로 저장할 2차원배열 변수 boomPos선언
        
        // 폭탄의 위치를 좌표로 저장하는 로직
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
        
        
        int[,] boardX = new int[boardH, boardV]; // 폭탄위치 + 위험지역을담을 2차원배열 변수 boardX선언
        Array.Copy(board, boardX, board.Length); // 깊은복사를 통해 일단 board를 boardX에 잠시 담는다.
        
        int bpRow = boomPos.GetLength(0); // boomPos의 행의길이는 폭탄의갯수와 같을것이므로 정수형변수에 잠시 담는다.
        
        // boardX에 위험지역을 2로 표시하는 로직
        for(int i=0; i<bpRow; i++)
        {
            int j = boomPos[i,0]; // 3
            int k = boomPos[i,1]; // 2
            for(int dj = -1; dj <= 1; dj++)
            {
                for(int dk = -1; dk <= 1; dk++)
                {
                    if (dj == 0 && dk == 0) 
                    {
                        continue; // 중심점은 무시
                    }

                    int newJ = j + dj;
                    int newK = k + dk;

                    // 배열 범위 확인
                    if ((newJ >= 0 && newJ < boardH) && (newK >= 0 && newK < boardV))
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
        // 런타임 오류??

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