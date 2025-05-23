#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	int LOG_MAX = log2(N) + 1;
	vector<vector<pii>> adj(N + 1);
	vector<int> depth(N + 1);
	vector<vector<int>> parent(LOG_MAX, vector<int>(N + 1));
	vector<vector<ll>> dist((ll)LOG_MAX, vector<ll>(N + 1));
	vector<vector<int>> LCA(N + 1, vector<int>(N + 1));
	vector<vector<vector<int>>> path(N + 1, vector<vector<int>>(N + 1));

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

			for (int i = 0; i < LOG_MAX; ++i)
			{
				if (parent[i][u] != parent[i][v])
				{
					u = parent[i][u];
					v = parent[i][v];
				}
			}

			return parent[0][u];
		};

	for (int u = 1; u <= N; ++u)
	{
		for (int v = u; v <= N; ++v)
		{
			if (u == v) LCA[u][v] = u;
			else
			{
				LCA[u][v] = findLCA(u, v);
				LCA[v][u] = LCA[u][v];
			}
		}
	}

	for (int u = 1; u <= N; ++u)
	{
		for (int v = 1; v <= N; ++v)
		{
			if (u == v) continue;

			int length = depth[u] + depth[v] - 2 * depth[LCA[u][v]];
			path[u][v] = vector<int>(length+1);
			path[u][v][0] = u;
			path[u][v][length] = v;
			int lca = LCA[u][v];
			for (int k = 1; k <= depth[u] - lca; ++k)
			{
				int node = u;
				for (int i = 0; i < LOG_MAX; ++i)
				{
					if (k & (1 << i)) node = parent[i][node];
				}
				path[u][v][k] = node;
			}
			for (int k = depth[u] - lca + 1; k < length && k > 0; ++k)
			{
				int node = v;
				int uToLCA = depth[u] - depth[lca];
				int height = depth[v] - (k-uToLCA + depth[lca]);
				for (int i = 0; i < LOG_MAX; ++i)
				{
					if (height & (1 << i)) node = parent[i][node];
				}
				path[u][v][k] = node;
			}
		}
	}

	int M; cin >> M;

	// dist가 sparse table이니까 u, v로부터 lca까지 dist 테이블로 구하고 더해서 캐싱해놔야함

	for (int i = 0; i < M; ++i)
	{
		int command, u, v; cin >> command;

		if (command == 1)
		{
			cin >> u >> v;
			cout << dist[u][v] << '\n';
		}
		else if (command == 2)
		{
			int k; cin >> u >> v >> k;
			cout << path[u][v][k] << '\n';
		}
	}

	return 0;
}