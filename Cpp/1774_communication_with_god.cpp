#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, int> pdi;

class DS {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DS(int n) {
        parent.resize(n+1);
		for (int i = 1; i <= n; ++i) parent[i] = i;
        rank.resize(n+1, 1);
    }

    int getParent(int n) {
        if (parent[n] == n) return n;
        return parent[n] = getParent(parent[n]);
    }

    void unite(int a, int b) {
        int ra = getParent(a);
        int rb = getParent(b);

        if (ra == rb) return;

        if (rank[ra] < rank[rb]) parent[ra] = rb;
        else
        {
            parent[rb] = ra;
            if (rank[ra] == rank[rb]) rank[ra]++;
        }
    }

    bool same(int a, int b) {
        return getParent(a) == getParent(b);
    }
};

vector<pii> coord;

double dist(int a, int b) {
	long long xx = abs(coord[a].first - coord[b].first);
	long long yy = abs(coord[a].second - coord[b].second);
	return sqrt(xx * xx + yy * yy);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	coord.resize(N+1);
	vector<bool> visited(N + 1);

	auto cmp = [](pdi& a, pdi& b) -> bool
		{
			return a.first > b.first;
		};

	priority_queue<pdi, vector<pdi>, decltype(cmp)> pq(cmp);


	DS ds(N);

	for (int n = 1; n <= N; ++n)
	{
		int X, Y; cin >> X >> Y;
		coord[n] = { X,Y };
	}

	

	for (int m = 1; m <= M; ++m)
	{
		int a, b; cin >> a >> b;
		ds.unite(a, b);
	}

	visited[1] = true;

	for (int i = 2; i <= N; ++i)
	{
		if (ds.same(1, i)) pq.push({ 0.0,i });
		else pq.push({ dist(1,i), i});
	}
	
	double ans = 0.0;
	while (!pq.empty())
	{
		auto [cost, idx] = pq.top();
		pq.pop();
		if (visited[idx]) continue;

		visited[idx] = true;
		ans += cost;

		for (int i = 1; i <= N; ++i)
		{
			if (!visited[i])
			{
				if (ds.same(idx, i)) pq.push({ 0.0,i });
				else pq.push({ dist(idx,i) , i });
			}
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << ans << '\n';

	return 0;
}