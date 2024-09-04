using System;

public class Solution 
{
    public int[] solution(string[] park, string[] routes) 
    {
        // park를 2차원 배열로 만들겠다.
        int parkRow = park.Length;
        int parkCol = park[0].Length;
        string[,] park2DList = new string[parkRow,parkCol];
        
        for(int i=0; i<parkRow; i++)
        {
            string temp = park[i];
            for(int j=0; j<parkCol; j++)
            {
                park2DList[i,j] = temp[j].ToString(); 
            }
        }
        
        
        // 명령횟수를 담는 변수
        int commandCount = routes.Length;
        
        // 방향을 담는 배열과 움직이는 칸 수를 담는 배열 
        string[] direction = new string[commandCount];
        int[] move = new int[commandCount];
        
        // 각각의 배열에 값을 할당하는 과정
        for(int i=0; i<commandCount; i++)
        {
            string temp = routes[i];
            direction[i] = temp[0].ToString();
            move[i] = Int32.Parse(temp[2].ToString());
        }
        
        // 결과로 담을 배열 만듬 초기값은 [0,0]
        int[] pos = new int[2];
        
        // 시작 위치 설정
        for(int i=0; i<parkRow; i++)
        {
            for(int j=0; j<parkCol; j++)
            {
                if(park2DList[i,j] == "S")
                {
                    pos[0] = i;
                    pos[1] = j;
                }
            }
        }
        
        // 로봇 강아지 이동 로직
        int cIdx = 0; // commandIndex => index번째 방향,move
        while(cIdx < commandCount)
        {
            bool isPossible = true;
            
            bool rightMove = true;
            bool leftMove = true;
            bool upMove = true;
            bool downMove = true;
          
            switch(direction[cIdx])
            {            
                case "E":
                    if(pos[1] + move[cIdx] > parkCol - 1)
                    {
                        rightMove = false;
                        cIdx++;
                        continue;
                    }
                    
                    if(rightMove)
                    {                   
                        for(int j=pos[1]; j<=pos[1] + move[cIdx]; j++)
                        {
                            if(park2DList[pos[0],j] == "X")
                            {
                                isPossible = false;
                                break;
                            }
                        }

                        if(isPossible)
                        {   
                            pos[1] += move[cIdx];
                        }
                    }                  
                    break;
                case "W":
                    if(pos[1] - move[cIdx] < 0)
                    {
                        leftMove = false;
                        cIdx++;
                        continue;
                    }
                    
                    if(leftMove)
                    {                       
                        for(int j=pos[1]; j>=pos[1] - move[cIdx]; j--)
                        {
                            if(park2DList[pos[0],j] == "X")
                            {
                                isPossible = false;
                                break;
                            }
                        }

                        if(isPossible)
                        {   
                            pos[1] -= move[cIdx];
                        }
                    }
                    break;
                case "N":
                    if(pos[0] - move[cIdx] < 0)
                    {
                        upMove = false;
                        cIdx++;
                        continue;
                    }
                    
                    if(upMove)
                    {                     
                        for(int i=pos[0]; i>=pos[0] - move[cIdx]; i--)
                        {
                            if(park2DList[i,pos[1]] == "X")
                            {
                                isPossible = false;
                                break;
                            }
                        }

                        if(isPossible)
                        {   
                            pos[0] -= move[cIdx];
                        }
                    }
                    break;
                case "S":
                    if(pos[0] + move[cIdx] > parkRow - 1)
                    {
                        downMove = false;
                        cIdx++;
                        continue;
                    }
                    
                    if(downMove)
                    {                        
                        for(int i=pos[0]; i<=pos[0] + move[cIdx]; i++)
                        {
                            if(park2DList[i,pos[1]] == "X")
                            {
                                isPossible = false;
                                break;
                            }
                        }

                        if(isPossible)
                        {   
                            pos[0] += move[cIdx];
                        }
                    }
                    break;
            }
            cIdx++;
        }        
        return pos;
    }
}