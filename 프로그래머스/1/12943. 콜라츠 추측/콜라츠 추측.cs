public class Solution 
{
    public int solution(int num) 
    {
        long n = num;
        int count = 0;
        
        if(n != 1)
        {          
            while(true)
            {
                if(n%2 == 0)
                {
                    n /= 2;
                    count++;
                }
                else
                {
                    n = n*3 + 1;
                    count++;
                }

                if(n == 1)
                {
                    break;
                }
            }
        }
        return (count < 500) ? count : -1;
    }
}