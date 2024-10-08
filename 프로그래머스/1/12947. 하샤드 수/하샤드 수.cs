public class Solution 
{
    public bool solution(int x) 
    {
        string strX = x.ToString();
        
        int sum = 0;
        foreach(char c in strX)
        {
            sum += c - '0';
        }
        
        return (x%sum == 0) ? true : false;
    }
}