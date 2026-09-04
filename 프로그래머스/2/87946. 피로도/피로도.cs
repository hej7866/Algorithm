using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    bool[] visited;
    int[] order;
    List<int> result;
    public int solution(int k, int[,] dungeons) 
    {
        int length = dungeons.GetLength(0);
        visited = new bool[length];
        order = new int[length];
        result = new List<int>();
        Search(0, k, length, dungeons);
        return result.ToArray().Max();
    }
    
    void Search(int depth, int k, int length, int[,] dungeons)
    {
        if (depth == length)
        {
            int count = 0;
            int remain = k;
            for (int i = 0; i < order.Length; i++)
            {
                int index = order[i];
                
                if(remain >= dungeons[index, 0])
                {
                    remain -= dungeons[index, 1];
                    count++;
                }
                else
                {
                    break;
                }
                
            }
            result.Add(count);
            Console.WriteLine();
            return;
        }

        for (int i = 0; i < length; i++)
        {
            if (visited[i])
                continue;

            visited[i] = true;
            order[depth] = i;

            Search(depth + 1, k, length , dungeons);
            visited[i] = false;
        }
    }
}
