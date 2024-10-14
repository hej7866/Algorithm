public class Solution 
{
    public int solution(int n) 
    {
        bool[] is_prime = new bool[n+1];
        
        for (int i = 0; i < is_prime.Length; i++)
        {
            is_prime[i] = true;
        }
        
        is_prime[0] = is_prime[1] = false;

        for (int i = 2; i * i <= n; i++) 
        {
            if (is_prime[i]) 
            {
                for (int j = i * i; j <= n; j += i) 
                {
                    is_prime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i <= n; i++) 
        {
            if (is_prime[i]) 
            {
                count++;
            }
        }

        return count;
    }
}