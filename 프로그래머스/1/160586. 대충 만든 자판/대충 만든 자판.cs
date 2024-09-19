using System;
using System.Collections.Generic;
using System.Linq;

public class Solution 
{
    public int[] solution(string[] keymap, string[] targets) 
    {   
        Dictionary<char, int> touchMap = new Dictionary<char, int>();
                   
        for(int i=0; i<keymap.Length; i++)
        {
            for(int j=0; j<keymap[i].Length; j++)
            {
                char c = keymap[i][j];
                if (touchMap.ContainsKey(c))
                {
                    touchMap[c] = Math.Min(touchMap[c], j + 1); // 최소 터치 수 갱신
                }
                else
                {
                    touchMap[c] = j + 1; // 첫 등장 시 터치 수 저장
                }
            }
        }
        
        int[] result = new int[targets.Length]; // 결과를 담을 배열의 길이는 targets의 길이와 같다.
        
        for (int i = 0; i < targets.Length; i++)
        {
            int sum = 0;
            foreach (char c in targets[i])
            {
                if (touchMap.TryGetValue(c, out int touchCount)) 
                {
                    sum += touchCount;
                }
                else
                {
                    sum = -1; // 문자가 키맵에 없으면 -1
                    break;
                }
            }
            result[i] = sum;
        }
        
        return result;
    }
}