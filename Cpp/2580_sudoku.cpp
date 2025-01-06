#include <iostream>   

using namespace std;
int N = 9;
int arr[10][10];
bool rows[10][10];
bool columns[10][10];
bool squares[10][10];

static int squareNum(int x, int y) {
    return (x / 3) * 3 + y / 3;
}

static bool sudoku(int z) {
    if (z == 81)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }

    int x = z / N;
    int y = z % N;
    if (arr[x][y] != 0)
    {
        return sudoku(z + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!rows[x][i] && !columns[y][i] && !squares[squareNum(x, y)][i])
            {
                rows[x][i] = columns[y][i] = squares[squareNum(x, y)][i] = true;
                arr[x][y] = i;
                if (sudoku(z + 1)) return true;
                arr[x][y] = 0;
                rows[x][i] = columns[y][i] = squares[squareNum(x, y)][i] = false;

            }
        }
    }
    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)
            {
                rows[i][arr[i][j]] = true;
                columns[j][arr[i][j]] = true;
                squares[squareNum(i, j)][arr[i][j]] = true;
            }
        }
    }
    sudoku(0);

    return 0;
}