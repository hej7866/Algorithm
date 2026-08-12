using System;

public class Solution 
{
    public int solution(int[] ingredient) 
    {
        int[] stack = new int[ingredient.Length];
        int top = -1;  // 스택의 맨 위 인덱스 (-1이면 비어있음)
        int count = 0;
        
        foreach (int item in ingredient)
        {
            stack[++top] = item;  // push
            
            // 맨 위 4개가 [1,3,2,1] (위에서부터 빵,고기,야채,빵) 인지 확인
            if (top >= 3 
                && stack[top] == 1 
                && stack[top-1] == 3 
                && stack[top-2] == 2 
                && stack[top-3] == 1)
            {
                top -= 4;  // 4개 pop (그냥 인덱스만 4 줄이면 됨)
                count++;
            }
        }
        
        return count;
    }
}