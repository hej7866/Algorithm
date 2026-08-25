using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(string dirs) 
    {
        Dictionary<char, int[]> dic = new Dictionary<char, int[]>();
        HashSet<((int, int), (int, int))> hashPos = new HashSet<((int, int), (int, int))>();
        
        dic['U'] = new int[] {0,1};
        dic['D'] = new int[] {0,-1};
        dic['L'] = new int[] {-1,0};
        dic['R'] = new int[] {1,0};
        
        int[] pos = new int[] {0,0};
        for(int i=0; i<dirs.Length; i++)
        {
            int[] arr = new int[2];

            if(Check(pos, dic, dirs[i]))
            {
                arr = dic[dirs[i]];
                var prevPos = (pos[0], pos[1]);
                pos[0] += arr[0];
                pos[1] += arr[1];
                var currentPos = (pos[0], pos[1]);
                
                // 항상 같은 순서로 정규화해서 저장 (역방향 이동도 같은 간선으로 취급)
                var edge = ComparePos(prevPos, currentPos) <= 0 
                    ? (prevPos, currentPos) 
                    : (currentPos, prevPos);
                hashPos.Add(edge);
            }
        }
        return hashPos.Count;
    }
    
    int ComparePos((int, int) a, (int, int) b)
    {
        if(a.Item1 != b.Item1) return a.Item1 - b.Item1;
        return a.Item2 - b.Item2;
    }
    
    bool Check(int[] pos, Dictionary<char, int[]> dic, char dir)
    {
        int[] arr = dic[dir];
        int dx = pos[0] + arr[0];
        int dy = pos[1] + arr[1];
        if(dx < -5 || dx > 5 || dy < -5 || dy > 5)
        {
            return false;
        }
        return true;
    }
}