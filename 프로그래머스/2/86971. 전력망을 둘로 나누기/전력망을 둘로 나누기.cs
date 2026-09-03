using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(int n, int[,] wires)
    {
        // 그래프 만들기
        Dictionary<int, List<int>> wireGraph = new Dictionary<int, List<int>>();

        for (int i = 1; i <= n; i++)
        {
            wireGraph[i] = new List<int>();
        }

        for (int i = 0; i < wires.GetLength(0); i++)
        {
            int start = wires[i, 0];
            int end = wires[i, 1];

            wireGraph[start].Add(end);
            wireGraph[end].Add(start);
        }

        int answer = n;

        // 간선을 하나씩 끊어본다.
        for (int i = 0; i < wires.GetLength(0); i++)
        {
            int skipStart = wires[i, 0];
            int skipEnd = wires[i, 1];

            int firstCount = BFS(skipStart, skipEnd, wireGraph);
            int secondCount = n - firstCount;
            
            int difference = Math.Abs(firstCount - secondCount);

            answer = Math.Min(answer, difference);
        }

        return answer;
    }

    private int BFS(int skipStart, int skipEnd, Dictionary<int, List<int>> wireGraph)
    {
        Queue<int> queue = new Queue<int>();
        HashSet<int> visited = new HashSet<int>();

        queue.Enqueue(skipStart);
        visited.Add(skipStart);

        while (queue.Count > 0)
        {
            int current = queue.Dequeue();

            foreach (int next in wireGraph[current])
            {
                // 끊기로 한 간선이면 이동하지 않는다.
                if ((current == skipStart && next == skipEnd) ||(current == skipEnd && next == skipStart))
                {
                    continue;
                }

                if (!visited.Contains(next))
                {
                    visited.Add(next);
                    queue.Enqueue(next);
                }
            }
        }

        return visited.Count;
    }
}