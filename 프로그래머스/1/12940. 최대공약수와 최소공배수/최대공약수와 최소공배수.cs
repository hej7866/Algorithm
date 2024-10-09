public class Solution 
{
    public int[] solution(int n, int m)
    {
        int tmpN = n;
        int tmpM = m;
        
        while (m != 0) 
        {
            int temp = m;
            m = n % m;
            n = temp;
        }
        int gcd = n;        
        int lcm = (tmpN * tmpM) / gcd ;
        
        int[] arr = new int[] { gcd, lcm};
        
        return arr;
    }
}