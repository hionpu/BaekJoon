#include <iostream>   

using namespace std;

const int MAX_N = 100000;
int arr[2][MAX_N + 1];
int dp[2][MAX_N + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		for (int row = 0; row < 2; row++)
		{
			for (int col = 1; col <= n; col++)
			{
				cin >> arr[row][col];
				dp[row][col] = 0;
			}
		}
		

		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		dp[0][2] = dp[1][1] + arr[0][2];
		dp[1][2] = dp[0][1] + arr[1][2];

		for (int col = 3; col <= n; col++)
		{
			for (int row = 0; row < 2; row++)
			{
				dp[row][col] = max(dp[(row + 1) % 2][col - 1], dp[(row + 1) % 2][col - 2])
					+ arr[row][col];
			}
		}

		cout << max(dp[0][n], dp[1][n]) << '\n';
	}
	return 0;
}