#include <iostream>   

using namespace std;
int dp[1001][31];
int plum[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T, W;
	cin >> T >> W;
	for (int i = 1; i <= T; i++)
	{
		cin >> plum[i];
	}

	dp[1][0] = plum[1] == 1 ? 1 : 0;
	dp[1][1] = plum[1] == 2 ? 1 : 0;
	for (int t = 2; t <= T; t++)
	{
		for (int w = 0; w <= W; w++)
		{
			int currentMax = 0;
			for (int k = 0; k <= w; k++)
			{
				currentMax = max(dp[t - 1][k], currentMax)  ;
			}
			dp[t][w] = currentMax + (plum[t] - 1 == w % 2 ? 1 : 0);
		}
	}

	int ans = 0;
	for (int i = 0; i <= W; i++)
	{
		ans = max(ans, dp[T][i]);
	}
	cout << ans << '\n';
	return 0;
}

