// See https://aka.ms/new-console-template for more information

using System.Diagnostics.CodeAnalysis;

class Program
{
    static void Main(string[] args)
    {
        var input = Console.ReadLine().Split();
        var boardSize = int.Parse(input[0]);
        var unitCount = int.Parse(input[1]);

        var board = new int[boardSize, boardSize];
        var map = new string[boardSize, boardSize];
        for (int i = 0; i < boardSize; i++)
        {
            var row = Console.ReadLine().Split();
            for (int j = 0; j < boardSize; j++)
            {
                board[i, j] = int.Parse(row[j]);
            }
        }

        ((int, int), int)[] unitVectors = new((int, int), int)[unitCount];
        for (int k = 0; k < unitCount; k++)
        {
            var row = Console.ReadLine().Split();
            var unitNum = k+1;
            var x = int.Parse(row[0])-1;
            var y = int.Parse(row[1])-1;
            var direction = int.Parse(row[2]);
            unitVectors[unitNum-1] = ((x, y), direction);
            map[x, y] = unitNum.ToString();
        }

        // temp
        for (int i = 0; i < boardSize; i++)
        {
            for (int j = 0; j < boardSize; j++)
            {
                Console.Write(map[i, j] + " ");
            }
            Console.WriteLine();
        }
        
        var unitArray = new string[unitCount];
        for (int i = 0; i < unitCount; i++)
        {
            unitArray[i] = (i + 1).ToString();
        }

        for (int turn = 1; turn <= 1000; turn++)
        {
            for (int unitNum = 1; unitNum <= unitCount; unitNum++)
            {
                
            }
        }

    }

    
}





