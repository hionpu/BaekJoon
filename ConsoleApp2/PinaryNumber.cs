using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class PinaryNumber
    {
        static void Main(string[] args)
        {
            int length = int.Parse(Console.ReadLine());
            long[] dp = new long[length + 1];
            dp[0] = 0;
            dp[1] = 1;
            
            
            for (int i = 2; i < length + 1; i++)
            {

                dp[i] = dp[i - 1] + dp[i - 2];

            }

            Console.WriteLine((long)dp[length]);
        }
    }
}
