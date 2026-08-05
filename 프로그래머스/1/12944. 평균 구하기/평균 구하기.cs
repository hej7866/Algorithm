public class Solution 
{
    public double solution(int[] arr) 
    {
        int ans = 0;
        foreach(int i in arr)
        {
            ans += i;
        }
        return (double)ans / arr.Length;
    }
}