public class Solution 
{
    public int solution(int[] arr) 
    {
        int answer = arr[0];
        for(int i=1; i<arr.Length; i++)
        {
            answer = LCM(answer, arr[i]);
        }
        return answer;
    }
    
    int LCM(int a, int b)
    {
        return a * b / GCD(a, b);
    }
    
    int GCD(int a, int b)
    {
        if(b == 0)
        {
            return a;
        }
        
        return GCD(b, a % b);
    }
}