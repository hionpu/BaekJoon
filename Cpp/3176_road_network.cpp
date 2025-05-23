#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int LOG_MAX = 20; // Usually sufficient, log2(100000) < 20

    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> depth(N + 1);
    vector<vector<int>> parent(LOG_MAX, vector<int>(N + 1, -1));
    vector<vector<int>> min_road(LOG_MAX, vector<int>(N + 1, INT_MAX));
    vector<vector<int>> max_road(LOG_MAX, vector<int>(N + 1, 0));

    for (int i = 0; i < N - 1; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({ B, C });
        graph[B].push_back({ A, C });
    }

    int root = 1; // Usually tree problems use 1-indexed nodes

    function<void(int, int, int, int)> dfs = [&](int node, int par, int dep, int road_len)
        {
            parent[0][node] = par;
            depth[node] = dep;
            min_road[0][node] = max_road[0][node] = road_len;

            for (auto& [next, cost] : graph[node])
            {
                if (next != par)
                {
                    dfs(next, node, dep + 1, cost);
                }
            }
        };

    dfs(root, -1, 0, 0);

    // Build binary lifting table with precomputed min/max
    for (int i = 1; i < LOG_MAX; ++i)
    {
        for (int node = 1; node <= N; ++node)
        {
            if (parent[i - 1][node] != -1)
            {
                parent[i][node] = parent[i - 1][parent[i - 1][node]];
                if (parent[i][node] != -1)
                {
                    min_road[i][node] = min(min_road[i - 1][node], min_road[i - 1][parent[i - 1][node]]);
                    max_road[i][node] = max(max_road[i - 1][node], max_road[i - 1][parent[i - 1][node]]);
                }
            }
        }
    }

    // Function to find min/max on path
    auto findMinMaxRoad = [&](int u, int v) -> pair<int, int>
        {
            int min_result = INT_MAX, max_result = 0;

            if (depth[u] < depth[v]) swap(u, v);

            // Bring u to same level as v
            int diff = depth[u] - depth[v];
            for (int i = 0; i < LOG_MAX; ++i)
            {
                if ((diff >> i) & 1)
                {
                    min_result = min(min_result, min_road[i][u]);
                    max_result = max(max_result, max_road[i][u]);
                    u = parent[i][u];
                }
            }

            if (u == v) return { min_result, max_result };

            // Binary search for LCA while accumulating min/max
            for (int i = LOG_MAX - 1; i >= 0; --i)
            {
                if (parent[i][u] != -1 && parent[i][u] != parent[i][v])
                {
                    min_result = min(min_result, min_road[i][u]);
                    min_result = min(min_result, min_road[i][v]);
                    max_result = max(max_result, max_road[i][u]);
                    max_result = max(max_result, max_road[i][v]);
                    u = parent[i][u];
                    v = parent[i][v];
                }
            }

            // Final step to LCA
            min_result = min(min_result, min_road[0][u]);
            min_result = min(min_result, min_road[0][v]);
            max_result = max(max_result, max_road[0][u]);
            max_result = max(max_result, max_road[0][v]);

            return { min_result, max_result };
        };

    int K;
    cin >> K;

    for (int i = 0; i < K; ++i)
    {
        int D, E;
        cin >> D >> E;

        auto [min_val, max_val] = findMinMaxRoad(D, E);
        cout << min_val << ' ' << max_val << '\n';
    }

    return 0;
}