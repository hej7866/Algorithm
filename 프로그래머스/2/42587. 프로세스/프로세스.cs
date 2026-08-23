using System;
using System.Collections.Generic;

public class Solution 
{
    public int solution(int[] priorities, int location) 
    {
        // 1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
        // 2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
        // 3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
        // 3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.
        Queue<(int a, int p)> q = new Queue<(int, int)>();
        List<int> list = new List<int>();
        int t = 0;
        foreach(int i in priorities)
        {
            t++;
            q.Enqueue((t,i));
        }
        // (1,2), (2,1), (3,3), (4,2);
        while(q.Count > 0)
        {
            (int a, int p) = q.Dequeue();
            bool b = false;
            foreach(var i in q)
            {
                if(p < i.p)
                {
                    q.Enqueue((a, p));
                    b = true;
                    break;
                }
            }
            if(b) continue;
            list.Add(a);
        }
        
        int c = 0;
        foreach(int i in list)
        {
            c++;
            Console.WriteLine(i);
            if(i - 1 == location)
            {
                break;
            }
        }
        return c;
    }
}