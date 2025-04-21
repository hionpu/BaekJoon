#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    vector<set<int>> adj;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
       
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int getParent(int n) {
        function<int(int)> find = [&](const int s) -> int
            {
                if (parent[s] == s) return s;
                return parent[s] = find(parent[s]);
            };
        return find(n);
    }

    bool unite(int a, int b) {
        int rootA = getParent(a);
        int rootB = getParent(b);

        
        if (rootA == rootB) return true;

        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
        }
        else
        {
            parent[rootB] = rootA;
            if (rank[rootA] == rank[rootB]) rank[rootA]++;
        }
        return false;
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
    int ans = 0;
    bool found = false;
    for (int tc = 1;tc<=m;++tc) 
    {
        int a, b; cin >> a >> b;
        if (!found && ds.unite(a, b))
        {
            ans = tc;
            found = true;
        }
    }
    cout << ans << '\n';
    
    return 0;
}