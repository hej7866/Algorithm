using System;

public class Solution 
{
    int result = 0;
    int t = 0;
    public int solution(int[] numbers, int target) 
    {
        t = target;
        DFS(0, 0, numbers);
        return result;
    }
    
    void DFS(int idx, int sum, int[] numbers)
    {
        if (idx == numbers.Length)
        {
            if(sum == t)
            {
                result++;
            }
            return;
        }

        DFS(idx + 1, sum + numbers[idx], numbers); // 양수로 선택
        DFS(idx + 1, sum - numbers[idx], numbers); // 음수로 선택
    }
}