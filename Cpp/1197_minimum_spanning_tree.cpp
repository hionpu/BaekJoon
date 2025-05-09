#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class DS {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DS(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
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

        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else
        {
            parent[rootB] = rootA;
            if (rank[rootA] == rank[rootB]) rank[rootA]++;
        }
    }

    bool same(int a, int b) {
        return getParent(a) == getParent(b);
    }
};

struct graph {
    int a;
    int b;
    int c;

    graph(int x, int y, int z) {
        a = x; b = y; c = z;
    }
};

bool cmp(graph a, graph b) {
    return a.c < b.c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E; cin >> V >> E;
    DS ds(V);
    vector<graph> graphs;
    for (int e = 1; e <= E; ++e)
    {
        int A, B, C; cin >> A >> B >> C;
        graph g(A, B, C);
        graphs.push_back(g);
    }

    sort(graphs.begin(), graphs.end(), cmp);
    long long ans = 0;
    for (auto& g : graphs)
    {
        if (ds.same(g.a, g.b)) continue;
        ds.unite(g.a, g.b);
        ans += g.c;
    }
    cout << ans << '\n';
    return 0;
}