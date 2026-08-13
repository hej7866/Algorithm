using System;

public class Solution 
{
    public int[] solution(string[] park, string[] routes) 
    {
        int[] result = new int[2];
        
        // 시작지점 할당
        for(int i=0; i<park.Length; i++)
        {
            for(int j=0; j<park[i].Length; j++)
            {
                if(park[i][j] == 'S')
                {
                    result[0] = i;
                    result[1] = j;
                }
            }
        }
        
        foreach(string route in routes)
        {
            string[] routeSplit = route.Split(' ');
            string dir = routeSplit[0];
            int count = Int32.Parse(routeSplit[1]);
            
            // 공원을 벗어나는지 체크
            bool isOut = false;
            switch(dir)
            {
                case "E":
                    if(result[1] + count > park[0].Length - 1)
                    {
                        isOut = true;
                    }
                    break;
                case "W":
                    if(result[1] - count < 0)
                    {
                        isOut = true;
                    }
                    break;
                case "N":
                    if(result[0] - count < 0)
                    {
                        isOut = true;
                    }
                    break;
                case "S":
                    if(result[0] + count > park.Length - 1)
                    {
                        isOut = true;
                    }
                    break;
            }
            
            if(isOut) continue;
            
            bool isMeet = false;
            switch(dir)
            {
                case "E":
                    for(int i=1; i<=count; i++)
                    {
                        if(park[result[0]][result[1] + i] == 'X')
                        {
                            isMeet  = true;
                            break;
                        }
                    }
                    break;
                case "W":
                    for(int i=1; i<=count; i++)
                    {
                        if(park[result[0]][result[1] - i] == 'X')
                        {
                            isMeet  = true;
                            break;
                        }
                    }
                    break;
                case "N":
                    for(int i=1; i<=count; i++)
                    {
                        if(park[result[0] - i][result[1]] == 'X')
                        {
                            isMeet  = true;
                            break;
                        }
                    }
                    break;
                case "S":
                    for(int i=1; i<=count; i++)
                    {
                        if(park[result[0] + i][result[1]] == 'X')
                        {
                            isMeet  = true;
                            break;
                        }
                    }
                    break;
            }
            
            if(isMeet) continue;
            
            if(!isMeet)
            {
                switch(dir)
                {
                    case "E":
                        result[1] += count ;
                        break;
                    case "W":
                        result[1] -= count;
                        break;
                    case "N":
                        result[0] -= count;
                        break;
                    case "S":
                        result[0] += count;
                        break;
                }
            }
        }
        return result;
        
    }
}