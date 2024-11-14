#include <iostream>

using namespace std;
int dp[1000001] = { 0 };

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = i;
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i > 1) dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[n]-1 << '\n';

	while (n > 0)
	{
		cout << n << ' ';
		if (n % 3 == 0 && dp[n] == dp[n / 3] + 1)
		{
			n /= 3;
		}
		else if (n % 2 == 0 && dp[n] == dp[n / 2] + 1)
		{
			n /= 2;
		}
		else
		{
			n -= 1;
		}
	}
}