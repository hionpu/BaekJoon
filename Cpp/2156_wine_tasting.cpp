#include <iostream>   

using namespace std;

int dp[10001];
int arr[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	dp[0] = 0; dp[1] = arr[1];
	if (n >= 2) dp[2] = arr[1] + arr[2];

	for (int i = 3; i <= n; i++)
	{
		dp[i] = max({
			dp[i - 1],
			dp[i - 2] + arr[i],
			dp[i - 3] + arr[i - 1] + arr[i]
			});
	}

	cout << dp[n] << '\n';

	return 0;

	
}