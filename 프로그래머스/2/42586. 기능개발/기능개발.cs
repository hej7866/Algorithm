using System;
using System.Collections.Generic;

public class Solution 
{
    public int[] solution(int[] progresses, int[] speeds) 
    {
        int c = progresses.Length;
        List<int> result = new List<int>();
        int prevDay = 0;
        for(int i=0; i<c; i++)
        {
            int speed = speeds[i]; // 개발 속도를 받아옴
            int progress = progresses[i]; // 작업의 진도를 받아옴
            
            int currentDay = 0;
            while(progress < 100)
            {
                progress += speed;
                currentDay++;
            }
            Console.WriteLine(currentDay);
            if(currentDay > prevDay)
            {
                result.Add(1);
            }
            else
            {
                result[result.Count - 1]++;
            }
            
            if(currentDay > prevDay)
            {
                prevDay = currentDay; 
            }
        }
        return result.ToArray();
    }
}