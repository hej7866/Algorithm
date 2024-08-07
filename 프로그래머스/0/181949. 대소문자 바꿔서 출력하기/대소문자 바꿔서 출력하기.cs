using System;

public class Example
{
    public static void Main()
    {
        String s;
        String a;
        String str = "";
        
        Console.Clear();
        s = Console.ReadLine();
        
        for (int index = 0; index < s.Length; index++){
            a = s.Substring(index, 1);
            if(char.IsUpper(a[0])) {
                str += char.ToLower(a[0]);
            }
            else if(char.IsLower(a[0])) {
                str += char.ToUpper(a[0]);
            }
            
        }
        Console.WriteLine(str);
    }
}