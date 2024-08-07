using System;

public class Example
{
    public static void Main()
    {
        String[] input;

        Console.Clear();
        input = Console.ReadLine().Split(' ');

        String s1 = input[0];
        int a = Int32.Parse(input[1]);

        for (int index = 1; index < a; index++)
        {
            s1 += input[0];
        }

        Console.WriteLine(s1);
    }
}
