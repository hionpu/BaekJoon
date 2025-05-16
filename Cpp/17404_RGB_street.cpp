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
		for (int j = 0; j < 3; ++j)
		{
			cin >> graph[i][j];
		}
	}

	// dp[i][j][k] = 첫번째 집 k색, 현재 i집까지 j색으로 칠함
	vector<vector<vector<int>>> dp(N, vector<vector<int>>(3, vector<int>(3, INT_MAX / 2)));

	for (int i = 0; i < 3; ++i) dp[0][i][i] = graph[0][i];

	for (int k = 0; k < 3; ++k)
	{
		for (int i = 1; i < N; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (i < N - 1)
				{
					dp[i][j][k] = min(dp[i - 1][(j + 1) % 3][k], dp[i - 1][(j + 2) % 3][k]) + graph[i][j];
				}
				else
				{
					if (j == k) continue;
					dp[i][j][k] = min(dp[i - 1][(j + 1) % 3][k], dp[i - 1][(j + 2) % 3][k]) + graph[i][j];
				}
			}
		}
	}
	int ans = INT_MAX / 2;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == j) continue;
			if (dp[N - 1][i][j] < ans) ans = dp[N - 1][i][j];
		}
	}

	cout << ans << '\n';

	return 0;
}