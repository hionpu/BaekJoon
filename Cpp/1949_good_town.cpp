#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class ET {
private:
	vector<vector<int>> graph;
	vector<bool> visited;
	vector<int> weight;
	vector<vector<int>> dp;

public:
	ET(int n) {
		graph.resize(n + 1);
		visited.resize(n + 1);
		weight.resize(n + 1);
		dp.resize(n + 1, vector<int>(2));
	}

	void add_node(int u, int v) {
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	void set_weight(int i, int w) {
		weight[i] = w;
	}

	void fill_dp(int cur) {
		if (visited[cur]) return;

		visited[cur] = true;

		dp[cur][1] = weight[cur];

		for (auto& next : graph[cur])
		{
			if (visited[next]) continue;

			fill_dp(next);

			 if (dp[next][0] < dp[next][1])
			 {
				 dp[cur][0] += dp[next][1];
			 }
			 else
			 {
				 dp[cur][0] += dp[next][0];
			 }

			dp[cur][1] += dp[next][0];

		}
	}

	int get_max(int cur) {
		return max(dp[cur][0], dp[cur][1]);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	ET et(N);
	for (int i = 1; i <= N; ++i)
	{
		int w; cin >> w;
		et.set_weight(i, w);
	}

	for (int i = 0; i < N - 1; ++i)
	{
		int u, v; cin >> u >> v;
		et.add_node(u, v);
	}

	et.fill_dp(1);

	cout << et.get_max(1) << '\n';



	return 0;
}