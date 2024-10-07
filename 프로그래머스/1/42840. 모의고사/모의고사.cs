using System;
using System.Collections.Generic;
using System.Linq; 

public class Solution 
{
    public int[] solution(int[] answers) 
    {
        int[] arr1 = new int[5] {1,2,3,4,5};
        int[] arr2 = new int[8] {2,1,2,3,2,4,2,5};
        int[] arr3 = new int[10] {3,3,1,1,2,2,4,4,5,5};
        
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        
        for(int i=0; i<answers.Length; i++)
        {
            if(answers[i] == arr1[i % arr1.Length]) { count1++; }
            if(answers[i] == arr2[i % arr2.Length]) { count2++; } 
            if(answers[i] == arr3[i % arr3.Length]) { count3++; }
        }
        
        int[] countArr = new int[3] { count1, count2, count3 };
        
        var scores = new List<(int count, int student)> 
        {
            (count1, 1),
            (count2, 2),
            (count3, 3)
        };

        scores = scores.OrderByDescending(s => s.count)
                       .ThenBy(s => s.student)
                       .ToList();
        
        var result = new List<int>();
        int highestScore = scores[0].count;

        foreach (var score in scores) 
        {
            if (score.count == highestScore) 
            {
                result.Add(score.student);
            }
        }

        return result.ToArray();
        
        
        
        
        
        
        return answers;
    }
}