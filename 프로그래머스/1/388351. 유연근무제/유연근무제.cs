using System;

public class Solution 
{
    public int solution(int[] schedules, int[,] timelogs, int startday) 
    {
        int n = timelogs.GetLength(0);
        int result = n;
        for(int i=0; i<n; i++) // n명을 순회하는데
        {
            int schedule = schedules[i]/100 * 60 + schedules[i]%100; // 출근 희망시간을 정수로 환산
            int currentDay = startday;
            for(int j=0; j<7; j++)
            {
                int timelog = timelogs[i,j]/100 * 60 + timelogs[i,j]%100; // 출근한 시간을 정수로 환산
                Console.WriteLine($"{schedule}, {timelog}");
                if(timelog - schedule > 10) // 일단 지각한 날인데
                {
                    
                    if(currentDay%7 == 6 || currentDay%7 == 0) // 주말이면 패스하고
                    {
                        currentDay = currentDay == 7 ? 1 : currentDay + 1;
                        continue;
                    }
                    result--; // 평일인데 10보다 차이가 크면 얘 제외 
                    break; //다음 사람으로 넘어가
                }
                currentDay = currentDay == 7 ? 1 : currentDay + 1;
            }
            
        }
        return result;
    }
}