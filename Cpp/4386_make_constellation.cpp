#include <iostream>   
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

typedef pair<float, float> pff;
typedef pair<float, int> pfi;
class DS {
private:
    map<pff, pff> parent;
    map<pff, int> rank;

public:
    DS() {

    }

    bool insert(pff a) {
        if (parent.contains(a)) return false;
        parent.insert({ a,a });
        rank[a] = 1;
        return true;
    }

    pff getParent(pff a) {
        if (parent[a] == a) return a;
        return parent[a] = getParent(parent[a]);
    }

    void unite(pff a, pff b) {
        pff rootA = getParent(a);
        pff rootB = getParent(b);

        if (rootA == rootB) return;

        if (rank[rootA] < rank[rootB]) parent[rootA] = rootB;
        else
        {
            parent[rootB] = rootA;
            if (rank[rootA] == rank[rootB]) rank[rootA]++;
        }
    }
};

float dist(pff a, pff b) {
    return sqrt(pow((b.first - a.first), 2) + pow((b.second - a.second), 2));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<vector<float>> map(n+1, vector<float>(n+1,0));
    vector<pff> star(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        float x, y; cin >> x >> y;
        star[i] = { x,y };
        if (i > 1)
        {
            for (int j = 1; j < i; ++j)
            {
                map[i][j] = map[j][i] = dist(star[i], star[j]);
            }
        }
    }

    

    // pii: {cost, starIdx}
    auto cmp = [](pfi a, pfi b) -> bool
        {
            return a.first > b.first;
        };
    priority_queue<pfi, vector<pfi>, decltype(cmp)> pq(cmp);
    vector<bool> visited(n + 1, false);
    float ans = 0;

    pq.push({ 0,1 });
    

    while (!pq.empty())
    {
        pfi t = pq.top();
        float cost = t.first;
        int idx = t.second;
        pq.pop();

        if (visited[idx]) continue;

        visited[idx] = true;
        ans += cost;

        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i] && i != idx)
            {
                float next_cost = dist(star[idx], star[i]);
                pq.push({ next_cost, i });
            }
        }
        
    }

    cout << ans << '\n';
    return 0;
}