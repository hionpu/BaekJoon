#include <iostream>   
#include <vector>

using namespace std;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string x, y;
	cin >> x >> y;
	
	int x_len = x.length();
	int y_len = y.length();

	for (int i = 1; i <= x_len; i++)
	{
		for (int j = 1; j <= y_len; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[x_len][y_len] << '\n';
	
	return 0;
}