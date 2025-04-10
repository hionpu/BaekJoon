#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;
unordered_map<int, vector<pii>> adj;
unordered_map<int, int> dists;

void dfs(int node) {
	for (auto& p : adj[node])
	{
		int next = p.first;
		int cost = p.second;
		if (dists.find(next) == dists.end())
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

	int V; cin >> V;
	for (int i = 0; i < V; ++i)
	{
		int a;
		cin >> a;
		while (true)
		{
			int b; cin >> b;
			if (b == -1) break;
			int c; cin >> c;
			adj[a].push_back({ b,c });
		}
	}

	int start = (*adj.begin()).first;
	dists[start] = 0;

	dfs(start);

	int dist = 0;
	int farthest = -1;
	for (auto& d : dists)
	{
		if (dist < d.second)
		{
			dist = d.second;
			farthest = d.first;
		}
	}

	dists.clear();

	dists[farthest] = 0;
	dfs(farthest);

	dist = 0;
	farthest = -1;

	for (auto& d : dists)
	{
		if (dist < d.second)
		{
			dist = d.second;
			farthest = d.first;
		}
	}

	cout << dist << '\n';

	return 0;
}