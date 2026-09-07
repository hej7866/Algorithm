using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(int[] cards)
    {
        bool[] visited = new bool[cards.Length];
        List<int> groupSizes = new List<int>();

        for (int i = 0; i < cards.Length; i++)
        {
            if (visited[i])
                continue;

            int current = i;
            int count = 0;

            while (!visited[current])
            {
                visited[current] = true;
                count++;
                current = cards[current] - 1;
            }

            groupSizes.Add(count);
        }

        groupSizes.Sort((a, b) => b.CompareTo(a));

        if (groupSizes.Count < 2)
            return 0;

        return groupSizes[0] * groupSizes[1];
    }
}