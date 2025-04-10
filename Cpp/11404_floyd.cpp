#include <iostream>   
#include <climits>

using namespace std;

const int NMAX = 100;
int n;
int graph[NMAX + 1][NMAX + 1];
int cost[NMAX + 1][NMAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m; cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cost[i][j] = i == j ? 0 : INT_MAX;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b],c);
    }
    
    for (int j = 1; j <= n; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int k = 1; k <= n; ++k)
            {
                if (cost[i][k] > cost[i][j] + cost[j][k] && cost[i][j] + cost[j][k] > 0)
                {
                    cost[i][k] = cost[i][j] + cost[j][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (cost[i][j] == INT_MAX) cost[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << cost[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}