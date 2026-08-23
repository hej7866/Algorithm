using System;
using System.Collections.Generic;

public class Solution 
{
    bool[] visited;
    HashSet<int> hash = new HashSet<int>();
    public int solution(string numbers) 
    {
        visited = new bool[numbers.Length]; // 필드로 한 번만 생성
        DFS(numbers, "");  
        
        int count = 0;
        foreach(int n in hash)
        {
            if(IsPrime(n))
            {
                count++;
            }
        }
        return count;
    }
    
    void DFS(string numbers, string current)
    {
        if(current.Length > 0)
        {
            hash.Add(int.Parse(current));
        }

        for(int i = 0; i < numbers.Length; i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                DFS(numbers, current + numbers[i]);
                visited[i] = false; // 되돌리기 (백트래킹)
            }
        }
    }
    
    bool IsPrime(int n)
    {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0) return false;
        }
        return true;
    }
}