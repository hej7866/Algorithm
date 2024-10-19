public class Solution 
{
    public string solution(int a, int b) 
    {
        int[,] arr = new int[,]
        {
            {1, 31}, {2, 29}, {3, 31}, {4, 30},
            {5, 31}, {6, 30}, {7, 31}, {8, 31},
            {9, 30}, {10, 31}, {11, 30}, {12, 31},
        };

        string[] v = new string[] {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

        int days = 0;
        for(int i=0; i<a-1; i++)
        {
            days += arr[i,1];
        }
        days += b - 1;
        return v[days%7];
    }
}