using System;
using System.Collections.Generic;

class Solution
{
    public int solution(int[] nums)
    {
        Func<int[], int, int, int, int> sumThreeElements = (arr, a, b, c) =>
        {
            return arr[a] + arr[b] + arr[c];
        };

        int count = 0;

        // 모든 조합을 위한 중첩 반복문
        for (int i = 0; i < nums.Length; i++)
        {
            for (int j = i + 1; j < nums.Length; j++)
            {
                for (int k = j + 1; k < nums.Length; k++)
                {
                    int sum = sumThreeElements(nums, i, j, k); // 람다 호출

                    bool isBool = false;
                    for (int m = 2; m < sum; m++)
                    {
                        if (sum % m == 0)
                        {
                            isBool = true;
                            break; // 더 이상 검사할 필요 없음
                        }
                    }
                    if (!isBool && sum > 1) // 소수일 경우 카운트
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
}