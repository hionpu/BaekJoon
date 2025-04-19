#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public: 
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY]) parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY]) parent[rootY] = rootX;
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    
    DisjointSet ds(n);

    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0) ds.unite(a, b);
        else if (op == 1)
        {
            if (ds.same(a, b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    
    return 0;
}