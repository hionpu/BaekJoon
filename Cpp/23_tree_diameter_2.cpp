#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> adj;
int dists[10001];
static void dfs(int node) {
	for (auto& p : adj[node])
	{
		int next = p.first;
		int cost = p.second;
		if (dists[next] < 0)
		{
			dists[next] = dists[node] + cost;
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	for (int i = 0; i < 10001; ++i) dists[i] = -1;

	adj.assign(n + 1, vector<pii>());

	for (int i = 0; i < n - 1; ++i)
	{
		int p, c, w; cin >> p >> c >> w;
		adj[p].push_back({ c,w });
		adj[c].push_back({ p,w });
	}

	dists[1] = 0;
	dfs(1);

	int maxDist = 0;
	int idx = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (maxDist < dists[i])
		{
			maxDist = dists[i];
			idx = i;
		}
	}

	for (int i = 0; i < 10001; ++i) dists[i] = -1;

	dists[idx] = 0;
	dfs(idx);

	maxDist = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (maxDist < dists[i])
		{
			maxDist = dists[i];
		}
	}

	cout << maxDist << '\n';

	return 0;
}