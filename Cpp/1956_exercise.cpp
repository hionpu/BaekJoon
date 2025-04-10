#include <iostream>   
#include <climits>
#include <algorithm>

using namespace std;

const int INF = 1e8;
const int VMAX = 400;

int V;
int dist[VMAX + 1][VMAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int E; cin >> V >> E;

    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < E; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int m = 1; m <= V; ++m)
    {
        for (int a = 1; a <= V; ++a)
        {
            for (int b = 1; b <= V; ++b)
            {
                if (dist[a][b] > dist[a][m] + dist[m][b])
                {
                    dist[a][b] = dist[a][m] + dist[m][b];
                }
            }
        }
    }
    int minCycle = dist[1][1];
    for (int i = 2; i <= V; ++i)
    {
        minCycle = min(dist[i][i], minCycle);
    }
    minCycle = minCycle >= INF ? -1 : minCycle;

    cout << minCycle << '\n';
    
    return 0;
}