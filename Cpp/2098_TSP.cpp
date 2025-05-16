#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;

	vector<vector<int>> graph(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> graph[i][j];
		}
	}

	// dp[visited][i] = visited 상태이면서 마지막 정점이 i인 경우의 최단 비용
	vector<vector<int>> dp(1 << N, vector<int>(N, INT_MAX/2));

	dp[1][0] = 0;

	for (int mask = 0; mask < (1 << N); ++mask)
	{
		for (int current = 0; current < N; ++current)
		{
			if (!(mask & (1 << current))) continue;

			for (int next = 0; next < N; ++next)
			{
				if (mask & (1 << next) || graph[current][next] == 0) continue;
				//if (dp[mask][current] == INT_MAX) continue;

				int next_mask = mask | (1 << next);
				dp[next_mask][next] = min(dp[next_mask][next], dp[mask][current] + graph[current][next]);
			}
		}
	}

	int ans = INT_MAX/2;
	int all_visited = (1 << N) - 1;

	for (int i = 0; i < N; ++i)
	{
		if (graph[i][0] > 0)
		{
			ans = min(ans, dp[all_visited][i] + graph[i][0]);
		}
	}

	cout << ans << '\n';


return 0;
}