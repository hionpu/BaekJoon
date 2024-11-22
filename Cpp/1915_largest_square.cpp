#include <iostream>   

using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = input[j - 1] - '0';
		}

	}

	int currentMax = 0;


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i][j] == 1)
			{
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
			}

			if (dp[i][j] > currentMax) currentMax = dp[i][j];
		}
	}

	cout << currentMax * currentMax << '\n';
	return 0;
}