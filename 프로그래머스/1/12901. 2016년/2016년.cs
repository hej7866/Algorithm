using System.Collections.Generic;
using System;

public class Solution 
{
    public string solution(int a, int b) 
    {
        int[] month = {0,31,29,31,30,31,30,31,31,30,31,30,31};

        string[] week = {"THU","FRI","SAT","SUN","MON","TUE","WED"};

        int day = b;

        for(int i = 1; i < a; i++)
        {
            day += month[i];
        }

        return week[day % 7];
    } 
}