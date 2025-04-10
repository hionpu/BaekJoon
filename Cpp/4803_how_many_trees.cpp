#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
bool visited[501];


bool isCyclic(int node, int parent) {
    visited[node] = true;
    for (auto& next : adj[node])
    {
        if (!visited[next])
        {
            if (isCyclic(next, node)) return true;
        }
        else if (next != parent)
        {
            return true ;
        }
    }
    return false;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 0;
    while (1)
    {
        int n, m, numTree = 0; cin >> n >> m;
        if (m == 0 && n == 0) break;
        adj.resize(n + 1);
        for (int i = 0; i < 501; ++i) visited[i] = false;
        for (int i = 1; i <= n; ++i)
        {
            adj[i].clear();
        }

        for (int i = 0; i < m; ++i)
        {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
            {
                if (!isCyclic(i, -1)) numTree++;
            }
        }
        cout << "Case " << ++T << ": ";

        if (numTree > 1)
        {
            cout << "A forest of " << numTree << ' ' << "trees." <<'\n';
        }
        else if (numTree == 1)
        {
            cout << "There is one tree." << '\n';
        }
        else
        {
            cout << "No trees." << '\n';
        }
    }
    return 0;
}