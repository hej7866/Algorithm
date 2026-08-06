using System;

public class Example
{
    public static void Main()
    {
        String[] s;

        Console.Clear();
        s = Console.ReadLine().Split(' ');

        int a = Int32.Parse(s[0]);
        int b = Int32.Parse(s[1]);

        string str = "";
        for(int i=0; i<a; i++)
        {
            str += '*';
        }
        
        for(int j=0; j<b; j++)
        {
            Console.WriteLine(str);
        }
    }
}