using System;

namespace ConsoleApplication
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            int n = -1;
            test(ref n);
            Console.WriteLine("{0}",n);
        }

        public static void test(ref int n)
        {
            n = 10;
        }
    }
}
