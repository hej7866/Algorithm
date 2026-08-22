using System;
using System.Collections.Generic;

public class Solution
{
    public int solution(int bridge_length, int weight, int[] truck_weights)
    {
        Queue<(int w, int enterTime)> bridge = new Queue<(int, int)>();
        int currentWeight = 0;
        int time = 0;
        int idx = 0; // 대기 트럭 인덱스
        int n = truck_weights.Length;

        while (idx < n || bridge.Count > 0)
        {
            time++;

            // 1. 다리 맨 앞 트럭이 다리를 다 건넜으면 내림
            if (bridge.Count > 0 && time - bridge.Peek().enterTime >= bridge_length)
            {
                currentWeight -= bridge.Dequeue().w;
            }

            // 2. 다음 트럭을 올릴 수 있으면 올림
            if (idx < n && currentWeight + truck_weights[idx] <= weight)
            {
                bridge.Enqueue((truck_weights[idx], time));
                currentWeight += truck_weights[idx];
                idx++;
            }
        }

        return time;
    }
}