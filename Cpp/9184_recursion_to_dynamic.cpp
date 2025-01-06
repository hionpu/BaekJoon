#include <iostream>   

using namespace std;
int dp[21][21][21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			for (int k = 0; k <= 20; k++)
			{
				if (i == 0 || j == 0 || k == 0)
				{
					dp[i][j][k] = 1;
				}
			}
		}
	}

	dp[1][1][1] = 2;
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			for (int k = 1; k <= 20; k++)
			{
				if (i < j && j < k)
				{
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k-1]  - dp[i][j - 1][k];
				}
				else
				{
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		int ans = 0;
		if (a <= 0 || b <= 0 || c <= 0) ans = 1;
		else if (a > 20 || b > 20 || c > 20) ans = dp[20][20][20];
		else
		{
			ans = dp[a][b][c];
		}

		cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << '\n';
	}

	return 0;
}