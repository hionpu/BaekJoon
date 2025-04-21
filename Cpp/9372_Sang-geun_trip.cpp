#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class DS {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> count;

public:
    DS(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 1);
        count.resize(n + 1, 1);
        count[0] = 0;
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }

    int getParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = getParent(parent[n]);
    }

    int same(int a, int b) {
        return getParent(a) == getParent(b);
    }

    void unite(int a, int b) {
        int rootA = getParent(a);
        int rootB = getParent(b);

        if (rootA == rootB) return;

        if (rank[rootA] < rank[rootB])
        {
            parent[rootA] = rootB;
            count[rootB] += count[rootA];
            count[rootB] = 0;
        }
        else
        {
            parent[rootB] = rootA;
            count[rootA] += count[rootB];
            count[rootA] = 0;
            if (rank[rootA] == rank[rootB]) rootA++;
        }
    }

    int getCount(int a) {
        return count[getParent(a)];
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

    for (int t = 0; t < T; ++t)
    {
        int N, M; cin >> N >> M;
        DS ds(N);
        int a, b; cin >> a >> b;
        ds.unite(a, b);
        int ans = 1;
        for (int m = 1; m < M; ++m)
        {
            int a, b; cin >> a >> b;
            if (ds.same(a, b)) continue;
            ds.unite(a, b);
            ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}