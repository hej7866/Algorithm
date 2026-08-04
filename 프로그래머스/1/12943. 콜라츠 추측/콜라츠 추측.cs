public class Solution 
{
    public int solution(int num) 
    {
        long value = num;
        int count = 0;

        while (value != 1 && count < 500)
        {
            if (value % 2 == 0)
            {
                value /= 2;
            }
            else
            {
                value = value * 3 + 1;
            }

            count++;
        }

        return value == 1 ? count : -1;
    }
}