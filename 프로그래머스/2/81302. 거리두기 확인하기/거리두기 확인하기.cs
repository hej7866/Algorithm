using System;
using System.Collections.Generic;

public class Solution
{
    int[] dr = { -1, 1, 0, 0 };
    int[] dc = { 0, 0, -1, 1 };

    public int[] solution(string[,] places)
    {
        int[] answer = new int[5];

        for (int p = 0; p < 5; p++)
        {
            // p번째 대기실의 5개 행을 뽑아서 배열로 구성
            string[] room = new string[5];
            for (int r = 0; r < 5; r++)
                room[r] = places[p, r];

            answer[p] = CheckDistancing(room) ? 1 : 0;
        }

        return answer;
    }

    bool CheckDistancing(string[] room)
    {
        char[][] grid = new char[5][];
        for (int i = 0; i < 5; i++)
            grid[i] = room[i].ToCharArray();

        for (int r = 0; r < 5; r++)
        {
            for (int c = 0; c < 5; c++)
            {
                if (grid[r][c] == 'P')
                {
                    if (!BfsCheck(grid, r, c))
                        return false;
                }
            }
        }

        return true;
    }

    bool BfsCheck(char[][] grid, int startR, int startC)
    {
        Queue<(int r, int c, int depth)> queue = new Queue<(int, int, int)>();
        bool[,] visited = new bool[5, 5];

        queue.Enqueue((startR, startC, 0));
        visited[startR, startC] = true;

        while (queue.Count > 0)
        {
            var (r, c, depth) = queue.Dequeue();

            if (depth >= 2) continue;

            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                if (visited[nr, nc]) continue;
                if (grid[nr][nc] == 'X') continue;

                if (grid[nr][nc] == 'P')
                    return false;

                visited[nr, nc] = true;
                queue.Enqueue((nr, nc, depth + 1));
            }
        }

        return true;
    }
}