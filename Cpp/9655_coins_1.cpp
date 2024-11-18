#include <iostream>   

using namespace std;
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	int m, n;
	int coins[100] = { 0 };
	cin >> n >> m;
	for (int j = 0; j < n; j++)
	{
		cin >> coins[j];
	}

	fill(dp, dp + m + 1, 0);

	dp[0] = 1;
	for (int j = 0; j < n; j++)
	{
		for (int k = coins[j]; k <= m; k++)
		{
			dp[k] += dp[k - coins[j]];
		}
	}

	cout << dp[m] << endl;

	return 0;
}