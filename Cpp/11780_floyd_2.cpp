#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>


using namespace std;

const int INF = 100'000'001;

int dist[101][101];
int graph[101][101];
int prevs[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        graph[a][b] = graph[a][b] == 0 ? c : min(graph[a][b], c);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j) dist[i][j] = 0;
            else if (graph[i][j] > 0)
            {
                dist[i][j] = graph[i][j];
                prevs[i][j] = i;
            }
            else dist[i][j] = INF;
        }
    }

    for (int mid = 1; mid <= n; ++mid)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][j] > dist[i][mid] + dist[mid][j])
                {
                    dist[i][j] = dist[i][mid] + dist[mid][j];
                    prevs[i][j] = prevs[mid][j];
                }
            }
        }
    }

    for (int i =1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] >= INF) cout << 0;
            else cout << dist[i][j];
            cout << " ";
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; ++i)
    {
        
        for (int j = 1; j <= n; ++j)
        {
            int numCity = 0;
            vector<int> path;
            if (dist[i][j] >= INF || dist[i][j] == 0)
            {
                cout << 0 << '\n';
                continue;
            }
            else
            {
                int current = j;
                path.push_back(current);
                numCity++;
                while (current != i)
                {
                    current = prevs[i][current];
                    path.push_back(current);
                    numCity++;
                }
            }
            cout << numCity << " ";
            reverse(path.begin(), path.end());
            for (auto& n : path) cout << n << " ";
            cout << '\n';
        }
    }

    return 0;
}