using System;

public class Solution 
{
    public int solution(string name) 
    {
        int n = name.Length;
        int result = 0;
        
        for (int i = 0; i < n; i++)
        {
            result += Math.Min(name[i] - 'A', 'Z' - name[i] + 1);
        }
        
        int moveCost = n - 1;
        
        for (int i = 0; i < n; i++)
        {
            int next = i + 1;
            
            while (next < n && name[next] == 'A')
            {
                next++;
            }
            
            int rightFirst = i * 2 + (n - next);
            int leftFirst = i + (n - next) * 2;
            
            moveCost = Math.Min(moveCost, rightFirst);
            moveCost = Math.Min(moveCost, leftFirst);
        }
        
        result += moveCost;
        
        return result;
    }
}