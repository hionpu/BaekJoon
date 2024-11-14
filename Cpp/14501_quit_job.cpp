#include <iostream>
#include <vector>

using namespace std;
int dp[17] = { 0 };
int days[16] = { 0 };
int pays[16] = { 0 };
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int d, p;
		cin >> d >> p;
		days[i] = d;
		pays[i] = p;
	}

	int currentMax = 0;

	for (int i = 1; i <= n + 1; i++)
	{
		dp[i] = max(dp[i], currentMax);

		if (i + days[i] <= n + 1 && i <= n)
		{
			dp[i + days[i]] = max(dp[i + days[i]], dp[i] + pays[i]);
		}
		currentMax = max(currentMax, dp[i]);
	}

	cout << currentMax << endl;

	return 0;


}