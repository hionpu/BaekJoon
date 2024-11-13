#include <iostream>   

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int arr[1000];
	int dp[1000];

	int max = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
			{
				dp[i] = dp[j] + arr[i];
			}
		}
		if (max < dp[i])
		{
			max = dp[i];
		}

	}
	cout << max;
	return 0;
}