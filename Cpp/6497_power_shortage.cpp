#include <iostream>   
#include <vector>
#include <algorithm>

using namespace std;

class DS {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DS(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int get_parent(int a) {
        if (parent[a] == a) return a;
        return parent[a] = get_parent(parent[a]);
    }

    void unite(int a, int b) {
        int root_a = get_parent(a);
        int root_b = get_parent(b);

        if (root_a == root_b) return;

        if (rank[root_a] < rank[root_b]) parent[root_a] = root_b;
        else
        {
            parent[root_b] = root_a;
            if (rank[root_a] == rank[root_b]) rank[root_a]++;
        }
    }

    bool connected(int a, int b) {
        return get_parent(a) == get_parent(b);
    }
};

struct edge {
    int x;
    int y;
    int c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        int m, n;
        cin >> m >> n;

        // Check termination condition
        if (m == 0 && n == 0) break;

        DS ds(m);
        vector<edge> eg;
        int total_cost = 0;

        for (int i = 0; i < n; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            total_cost += z;
            eg.push_back({ x, y, z });
        }

        sort(eg.begin(), eg.end(), [](const edge& a, const edge& b)
            {
                return a.c < b.c;
            });

        int mst_cost = 0;

        for (auto& e : eg)
        {
            if (ds.connected(e.x, e.y)) continue;
            ds.unite(e.x, e.y);
            mst_cost += e.c;
        }

        cout << total_cost - mst_cost << '\n';
    }

    return 0;
}