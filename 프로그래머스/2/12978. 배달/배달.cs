using System;
using System.Collections.Generic;

class Solution
{
    public int solution(int N, int[,] road, int K)
    {
        List<(int next, int weight)>[] graph = new List<(int, int)>[N + 1];
        for(int i=1; i<=N; i++)
        {
            graph[i] = new List<(int, int)>();
        }
        int roadCount = road.GetLength(0);
        for(int i=0; i<roadCount; i++)
        {
            int a = road[i, 0];
            int b = road[i, 1];
            int c = road[i, 2];
            
            // 양방향 도로니까 양쪽 다 추가
            graph[a].Add((b, c));
            graph[b].Add((a, c));
        }
        
        // 2. 다익스트라로 1번 마을 기준 최단거리 배열 구하기
        int[] dist = Dijkstra(1, N, graph);
        
        // 3. K 이하인 마을 개수 세기
        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            if (dist[i] <= K) count++;
        }

        return count;
    }   
    
    public int[] Dijkstra(int start, int N, List<(int next, int weight)>[] graph)
    {
        int[] dist = new int[N + 1];
        Array.Fill(dist, int.MaxValue);
        dist[start] = 0;
        bool[] visited = new bool[N + 1];

        for (int i = 0; i < N; i++)
        {
            // 미방문 중 최단거리 노드 찾기 - O(V)
            int cur = -1;
            int minDist = int.MaxValue;
            for (int j = 1; j <= N; j++)
            {
                if (!visited[j] && dist[j] < minDist)
                {
                    minDist = dist[j];
                    cur = j;
                }
            }
            if (cur == -1) break; // 남은 노드가 모두 도달 불가능

            visited[cur] = true;

            // 인접 노드 완화 - O(V) (인접리스트면 간선 수만큼)
            foreach (var (next, weight) in graph[cur])
            {
                if (dist[cur] != int.MaxValue && dist[cur] + weight < dist[next])
                {
                    dist[next] = dist[cur] + weight;
                }
            }
        }

        return dist;
    }
}