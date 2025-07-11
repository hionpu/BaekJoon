#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int getAncester(int node, int k, int LOG_MAX, const vector<vector<int>>& parentTable) {
	for (int i = 0; i < LOG_MAX; ++i)
	{
		if ((k >> i) & 1)
		{
			node = parentTable[i][node];
			if (node == 0) break;
		}
	}
	return node;
}

ll getPathSumToAncestor(int node, int ancestorDepth, int LOG_MAX, const vector<int>& depthTable, 
	const vector<vector<int>>& parentTable, const vector<vector<ll>>& distTable) {
	ll currentSum = 0;
	int currentNode = node;
	int stepsToJump = depthTable[currentNode] - ancestorDepth;

	for (int i = LOG_MAX - 1; i >= 0; --i)
	{
		if ((stepsToJump >> i) & 1)
		{
			currentSum += distTable[i][currentNode];
			currentNode = parentTable[i][currentNode];
		}
	}

	return currentSum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int LOG_MAX = log2(N) + 1;
	if (N > 0) LOG_MAX = floor(log2(N)) + 1;
	else LOG_MAX = 1; // Handle N=0 or N=1 case for log2

	vector<vector<pii>> adj(N + 1);
	vector<int> depth(N + 1);
	vector<vector<int>> parent(LOG_MAX, vector<int>(N + 1, 0)); // Initialize with 0
	vector<vector<ll>> dist(LOG_MAX, vector<ll>(N + 1, 0LL)); // Initialize with 0

	for (int i = 0; i < N - 1; ++i)
	{
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	function<void(int, int, int, int)> dfs = [&](int node, int par, int dep, int cost)
		{
			parent[0][node] = par;
			depth[node] = dep;
			dist[0][node] = cost;

			for (auto& next : adj[node])
			{
				if (next.first != par)
				{
					dfs(next.first, node, dep + 1, next.second);
				}
			}
		};

	dfs(1, 0, 0, 0);

	for (int i = 1; i < LOG_MAX; ++i)
	{
		for (int n = 1; n <= N; ++n)
		{
			if (parent[i - 1][n] == 0) continue;

			parent[i][n] = parent[i - 1][parent[i - 1][n]];
			dist[i][n] = dist[i - 1][n] + dist[i - 1][parent[i - 1][n]];
		}
	}

	function<int(int, int)> findLCA = [&](int u, int v) -> int
		{
			// always depth[u] < depth[v]
			if (depth[u] > depth[v]) swap(u, v);

			int diff = depth[v] - depth[u];

			for (int i = 0; i < LOG_MAX; ++i)
			{
				if (diff & (1 << i))
				{
					v = parent[i][v];
				}
			}

			if (u == v) return u;

			for (int i = LOG_MAX-1; i >=0; --i)
			{
				if (parent[i][u] != 0 && parent[i][u] != parent[i][v])
				{
					u = parent[i][u];
					v = parent[i][v];
				}
			}

			return parent[0][u];
		};



	int M; cin >> M;

	// dist가 sparse table이니까 u, v로부터 lca까지 dist 테이블로 구하고 더해서 캐싱해놔야함

	for (int i = 0; i < M; ++i)
	{
		int command, u, v; cin >> command;

		if (command == 1)
		{
			cin >> u >> v;
			int lca = findLCA(u, v);
			ll distUtoLCA = getPathSumToAncestor(u, depth[lca], LOG_MAX, depth, parent, dist);
			ll distVtoLCA = getPathSumToAncestor(v, depth[lca], LOG_MAX, depth, parent, dist);

			cout << distUtoLCA + distVtoLCA << '\n';
		}
		else if (command == 2)
		{
			int k; cin >> u >> v >> k;
			int lca = findLCA(u, v);

			int path_u_to_lca_len = depth[u] - depth[lca];
			if (k - 1 < path_u_to_lca_len)
			{
				cout << getAncester(u, k - 1, LOG_MAX, parent) << '\n';
			}
			else
			{
				int steps_from_lca_to_target = (k - 1) - path_u_to_lca_len;
				int path_lca_to_v_len = depth[v] - depth[lca];
				int steps_up_from_v = path_lca_to_v_len - steps_from_lca_to_target;
				cout << getAncester(v, steps_up_from_v, LOG_MAX, parent) << '\n';
			}
		}
	}

	return 0;
}