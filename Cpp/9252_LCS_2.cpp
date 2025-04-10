#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int NMAX = 1000;

int LCS[NMAX + 1][NMAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b; cin >> a >> b;
    for (int i = 0; i < a.length(); ++i)
    {
        for (int j = 0; j < b.length(); ++j)
        {
            if (a[i] == b[j]) LCS[i + 1][j + 1] = LCS[i][j] + 1;
            else (LCS[i + 1][j + 1] = max(LCS[i][j + 1], LCS[i + 1][j]));
        }
    }

    cout << LCS[a.length()][b.length()] <<'\n';

    int x = a.length(), y = b.length();
    vector<char> result;

    while (!(x == 0 && y == 0))
    {
        if (x>0 && LCS[x][y] == LCS[x - 1][y] )
        {
            x--;
        }
        else if (y >0 && LCS[x][y] == LCS[x][y - 1])
        {
            y--;
        }
        else
        {
            result.push_back(a[x-1]);
            x--; y--;
        }
    }

    if (result.size() > 0)
    {
        reverse(result.begin(), result.end());
        for (auto& c : result)
        {
            cout << c;
        }
        cout << '\n';
    }
   

    return 0;
}