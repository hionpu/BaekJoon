#include <iostream>   

using namespace std;

int main() {
	int n;
	cin >> n;

	long long dp[91] = { 0, 1 };
	for (int i = 1; i <= n; i++)
	{
		dp[i + 1] = dp[i] + dp[i - 1];
	}

	cout << dp[n];

	return 0;
}
