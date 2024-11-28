#include <iostream>   

using namespace std;
int map[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; i++)
    {
        int corners[4] = { 0, 0, 0, 0 };
        for (int j = 0; j < 4; j++)
        {
            cin >> corners[j];
        }
        for (int x = corners[0]; x< corners[2]; x++)
        {
            for (int y = corners[1]; y < corners[3]; y++)
            {
                map[x][y] = 1;
            }
        }
    }
    int area = 0;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            area += map[i][j];
        }
    }

    cout << area << '\n';

    return 0;
}