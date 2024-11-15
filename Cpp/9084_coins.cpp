#include <iostream>   

using namespace std;
int dp[10001];

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int m, n;
		int coins[20] = { 0 };
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> coins[j];
		}
		cin >> m;

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
	}

	return 0;
}
