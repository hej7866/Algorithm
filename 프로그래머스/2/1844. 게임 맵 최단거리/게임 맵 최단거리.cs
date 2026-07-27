using System.Collections.Generic;

public class Solution
{
    public int solution(int[,] maps)
    {
        int rowCount = maps.GetLength(0);
        int columnCount = maps.GetLength(1);

        // 상, 하, 좌, 우
        int[] dy = { -1, 1, 0, 0 };
        int[] dx = { 0, 0, -1, 1 };

        Queue<(int y, int x)> queue = new Queue<(int y, int x)>();

        queue.Enqueue((0, 0));

        while (queue.Count > 0)
        {
            var current = queue.Dequeue();

            int currentY = current.y;
            int currentX = current.x;

            for (int i = 0; i < 4; i++)
            {
                int nextY = currentY + dy[i];
                int nextX = currentX + dx[i];

                // 맵 밖인지 확인
                if (nextY < 0 || nextY >= rowCount ||
                    nextX < 0 || nextX >= columnCount)
                {
                    continue;
                }

                // 벽이거나 이미 방문한 곳
                if (maps[nextY, nextX] != 1)
                {
                    continue;
                }

                // 이전 칸까지의 거리 + 1
                maps[nextY, nextX] = maps[currentY, currentX] + 1;

                queue.Enqueue((nextY, nextX));
            }
        }

        int answer = maps[rowCount - 1, columnCount - 1];

        return answer == 1 ? -1 : answer;
    }
}