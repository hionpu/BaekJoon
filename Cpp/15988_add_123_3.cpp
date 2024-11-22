#include <iostream>   
#include <vector>

using namespace std;
const int MAXN = 1000000;
int dp[MAXN +1];
const int MOD = 1000000009;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	int T;
	cin >> T;

	for (int i = 4; i <= MAXN; i++)
	{
		dp[i] = ((dp[i - 1]  + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
	}

	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
