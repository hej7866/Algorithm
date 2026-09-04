using System;
using System.Collections.Generic;

public class Solution 
{
    int answer;
    public int solution(int n, int k) 
    {
        answer = 0;
        int num = n;
        string result = Solve01(num, k);
        Solve02(result);
        return answer;
    }
    
    string Solve01(int num, int k)
    {
        List<int> list = new List<int>();
        while(num > 0)
        {
            list.Add(num % k);
            num /= k;
        }
        
        string result = "";
        for(int i=list.Count - 1; i>=0; i--)
        {
            result += list[i].ToString();
        }
        return result;
    }
    
    void Solve02(string str)
    {
        string tmp = "";
        foreach(char c in str)
        {
            if(c != '0')
            {
                tmp += c;
            }
            else
            {
                if(tmp.Length > 0 && tmp != "1") 
                {
                    if(IsPrime(tmp))
                    {
                        answer++;
                    }
                }
                tmp = "";
            }
        }
        
        if(tmp.Length > 0 && tmp != "1") 
        {
            if(IsPrime(tmp))
            {
                answer++;
            }
        }
    }
    
    bool IsPrime(string s)
    {
        long num = long.Parse(s);
        for(long i=2; i * i <= num; i++)
        {
            if(num % i == 0)
            {
                return false;
            }
        }
        return true;
    }
}