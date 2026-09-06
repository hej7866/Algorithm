using System;

public class Solution
{
    int[] answer = { -1 };
    int maxDifference;

    public int[] solution(int n, int[] info)
    {
        maxDifference = 0;
        int[] lion = new int[11];
        DFS(0, n, lion, info);
        return answer;
    }

    void DFS(int index, int remain, int[] lion, int[] info)
    {
        if (index == 10)
        {
            lion[10] = remain;
            CheckResult(lion, info);
            lion[10] = 0;
            return;
        }

        int need = info[index] + 1;

        if (remain >= need)
        {
            lion[index] = need;
            DFS(index + 1, remain - need, lion, info);
        }

        lion[index] = 0;
        DFS(index + 1, remain, lion, info);
    }

    void CheckResult(int[] lion, int[] info)
    {
        int lionTotal = 0;
        int apeachTotal = 0;

        for (int i = 0; i < 11; i++)
        {
            if (lion[i] == 0 && info[i] == 0)
                continue;

            if (lion[i] > info[i])
            {
                lionTotal += 10 - i;
            }
            else
            {
                apeachTotal += 10 - i;
            }
        }

        int difference = lionTotal - apeachTotal;

        if (difference <= 0)
            return;

        if (difference > maxDifference)
        {
            maxDifference = difference;
            answer = (int[])lion.Clone();
            return;
        }

        if (difference == maxDifference && IsBetterByLowScore(lion))
        {
            answer = (int[])lion.Clone();
        }
    }
    
    bool IsBetterByLowScore(int[] lion)
    {
        for (int i = 10; i >= 0; i--)
        {
            if (lion[i] > answer[i])
                return true;

            if (lion[i] < answer[i])
                return false;
        }

        return false;
    }
}