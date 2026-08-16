using System;
using System.Collections.Generic;

class Solution 
{
    public int solution(int[,] maps) 
    {
        int rows = maps.GetLength(0);
        int cols = maps.GetLength(1);
        int[,] dist = BFS(maps, rows, cols); 
        
        int result = dist[rows - 1, cols - 1];
        return result == 0 ? -1 : result;
    }
    
    private int[,] BFS(int[,] maps, int rows, int cols)
    {
        int[,] dist = new int[rows, cols];
        bool[,] visited = new bool[rows, cols];
        
        int[] dr = {-1,1,0,0};
        int[] dc = {0,0,-1,1};
        
        Queue<(int r, int c)> queue = new Queue<(int r, int c)>();
        queue.Enqueue((0,0));
        dist[0,0] = 1;
        visited[0,0] = true;
        
        while(queue.Count > 0)
        {
            var (r, c) = queue.Dequeue();
            
            for(int i=0; i<4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                {
                    continue;
                }
                if(maps[nr,nc] == 0)
                {
                    continue;
                }
                if(visited[nr,nc])
                {
                    continue;
                }
                
                visited[nr, nc] = true;
                dist[nr, nc] = dist[r, c] + 1;
                queue.Enqueue((nr, nc));
            }
        }
        return dist;
    }   
}