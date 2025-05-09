#include <bits/stdc++.h>


using namespace std;


class DisjointSet {
private:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank;
    unordered_map<int, int> count;

public:
    DisjointSet(int n) {
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int getParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = getParent(parent[n]);
    }

    void unite(int a, int b) {
        int rootA = getParent(a);
        int rootB = getParent(b);
        if (rootA == rootB) return; 

        if (rootA > rootB) parent[rootB] = rootA;
        else if (rootB > rootA) parent[rootA] = rootB;
        else
        {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }

    bool same(int a, int b) {
        return getParent(a) == getParent(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    DisjointSet ds(n);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int c; cin >> c;
            if (c == 1)
            {
                ds.unite(i, j);
            }
        }
    }

    int f; cin >> f;
    int v;
    bool ans = true;
    for (int i = 0;i<m-1;++i)
    {
        cin >> v;
        ans &= ds.same(f, v);
        f = v;
    }

    if (ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}