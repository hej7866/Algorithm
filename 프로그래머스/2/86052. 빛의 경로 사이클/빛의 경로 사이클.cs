using System;
using System.Collections.Generic;

public class Solution 
{
    int[] dr = {-1,0,1,0};  // 0=위, 1=오른쪽, 2=아래, 3=왼쪽
    int[] dc = {0,1,0,-1};
    
    public int[] solution(string[] grid) 
    {
        char[][] charGrid = new char[grid.Length][];
        for(int i=0; i<grid.Length; i++)
        {
            charGrid[i] = grid[i].ToCharArray();
        }
         List<int> cycles = Move(charGrid);
        cycles.Sort();
        return cycles.ToArray();
    }
    
    List<int> Move(char[][] grid)
    {
        int h = grid.Length;
        int w = grid[0].Length;
        bool[,,] visited = new bool[h, w, 4]; // 4방향
        List<int> cycles = new List<int>();

        for(int r=0; r<h; r++)
        {
            for(int c=0; c<w; c++)
            {
                for(int d=0; d<4; d++)
                {
                    if(visited[r,c,d]) continue;

                    int cnt = 0;
                    int cr = r, cc = c, cd = d;

                    while(!visited[cr,cc,cd])
                    {
                        visited[cr,cc,cd] = true;
                        cnt++;
                        // 현재 칸의 문자(S/L/R)에 따라 cd(방향) 갱신
                        if(grid[cr][cc] == 'S')
                        {
                            cd = cd;
                        }
                        else if(grid[cr][cc] == 'L')
                        {
                            cd = (cd + 3) % 4;
                        }
                        else if(grid[cr][cc] == 'R')
                        {
                            cd = (cd + 1) % 4;
                        }
                        // cd에 따라 cr, cc를 다음 칸으로 이동 (격자 순환 포함)
                        
                        cr = (cr + dr[cd] + h) % h;
                        cc = (cc + dc[cd] + w) % w;
                    }

                    cycles.Add(cnt);
                }
            }
        }
        return cycles;
    }
}