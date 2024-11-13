using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class IntegerTriangle
    {
        static void Main(string[] args)
        {
            int rowNum = int.Parse(Console.ReadLine());
            int[,] triangle = new int[rowNum, rowNum];
            int[,] dp = new int[rowNum, rowNum];
            for (int i = 0; i < rowNum; i++)
            {
                int[] row = Console.ReadLine().Split().Select(int.Parse).ToArray();
                for (int j = 0; j < i + 1; j++)
                {
                    triangle[i, j] = row[j];
                }
            }
            dp[0, 0] = triangle[0, 0];
            for (int i = 1; i < rowNum; i++)
            {
                for (int j = 0; j < i + 1; j++)
                {
                    if (j == 0)
                    {
                        dp[i, j] = dp[i - 1, j] + triangle[i, j];
                    }
                    else if (j == i)
                    {
                        dp[i, j] = dp[i - 1, j - 1] + triangle[i, j];
                    }
                    else
                    {
                        dp[i, j] = Math.Max(dp[i - 1, j - 1], dp[i - 1, j]) + triangle[i, j];
                    }
                }
            }
            int max = dp[rowNum - 1, 0];
            
            for (int j = 1; j < rowNum; j++)
            {
                if (dp[rowNum - 1, j] > max)
                {
                    max = dp[rowNum - 1, j];
                }
            }
            Console.WriteLine(max);
        }
    }
}
