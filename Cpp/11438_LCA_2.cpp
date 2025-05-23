#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int MAX_LOG = log2(100000) + 1;

    vector<vector<int>> tree(N+1);
    vector<int> depth(N + 1);
    vector<vector<int>> sparse(MAX_LOG, vector<int>(N + 1));

    for (int i = 0; i < N - 1; ++i)
    {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    function<void(int, int, int)> dfs = [&](int node, int parent, int dep)
        {
            depth[node] = dep;
            sparse[0][node] = parent;

            for (int next : tree[node])
            {
                if (next != parent)
                {
                    dfs(next, node, dep + 1);
                }
            }
        };

    dfs(1, 0, 0);

    for (int i = 1; i < MAX_LOG; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            sparse[i][j] = sparse[i - 1][sparse[i - 1][j]];
        }
    }

    int M; cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int a, b; cin >> a >> b;

        int depthA = depth[a];
        int depthB = depth[b];

        int deeper = depthA > depthB ? a : b;
        int shallower = depthA > depthB ? b : a;

        int diff = abs(depthA - depthB);

        for (int n = MAX_LOG; n >= 0; --n)
        {
            if (diff & (1 << n))
            {
                deeper = sparse[n][deeper];
            }
        }

        if (deeper == shallower)
        {
            cout << deeper << '\n';
            continue;
        }

        // now depth is equalized.
        for (int n = MAX_LOG-1; n >= 0; --n)
        {
            if (sparse[n][deeper] != sparse[n][shallower])
            {
                deeper = sparse[n][deeper];
                shallower = sparse[n][shallower];
            }
        }

        cout << sparse[0][deeper] << '\n';
    }

    return 0;
}