using System;

public class Solution 
{
    public int solution(int n) 
    {
        bool isSquare = false;
        for(int i=1; i<=1000; i++) {
            if(n == i * i) {
                isSquare = true;
            }
        }
        int answer = 0;
        return answer = isSquare ? 1 : 2;
    }
}