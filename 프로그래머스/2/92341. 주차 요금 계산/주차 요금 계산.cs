using System;
using System.Collections.Generic;

public class Solution
{
    public int[] solution(int[] fees, string[] records)
    {
        Dictionary<string, int> inTimes = new Dictionary<string, int>();
        Dictionary<string, int> totalTimes = new Dictionary<string, int>();

        foreach (string record in records)
        {
            string[] split = record.Split(' ');
            string time = split[0];
            string carNumber = split[1];
            string state = split[2];

            int currentTime = TimeCalculator(time);

            if (!totalTimes.ContainsKey(carNumber))
            {
                totalTimes[carNumber] = 0;
            }

            if (state == "IN")
            {
                inTimes[carNumber] = currentTime;
            }
            else
            {
                totalTimes[carNumber] += currentTime - inTimes[carNumber];
                inTimes.Remove(carNumber);
            }
        }

        foreach (var car in inTimes)
        {
            totalTimes[car.Key] += 1439 - car.Value;
        }

        List<string> carNumbers = new List<string>(totalTimes.Keys);
        carNumbers.Sort();

        List<int> result = new List<int>();

        foreach (string carNumber in carNumbers)
        {
            int totalTime = totalTimes[carNumber];

            if (totalTime <= fees[0])
            {
                result.Add(fees[1]);
                continue;
            }

            int extraTime = totalTime - fees[0];
            int unitCount = (extraTime + fees[2] - 1) / fees[2]; // ⌈a⌉
            int money = fees[1] + unitCount * fees[3];

            result.Add(money);
        }

        return result.ToArray();
    }

    int TimeCalculator(string time)
    {
        string[] timeSplit = time.Split(':');
        int hour = int.Parse(timeSplit[0]);
        int minute = int.Parse(timeSplit[1]);

        return hour * 60 + minute;
    }
}