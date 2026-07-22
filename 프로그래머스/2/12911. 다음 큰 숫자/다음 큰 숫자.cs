public class Solution
{
    public int solution(int n)
    {
        int targetCount = CountOne(n);
        int answer = n + 1;

        while (CountOne(answer) != targetCount)
        {
            answer++;
        }

        return answer;
    }

    private int CountOne(int number)
    {
        int count = 0;

        while (number > 0)
        {
            if (number % 2 == 1)
            {
                count++;
            }

            number /= 2;
        }

        return count;
    }
}