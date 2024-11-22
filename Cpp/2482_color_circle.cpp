#include <iostream>   

using namespace std;
const int MOD = 1000000003;
int dp[1003][1003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	cin >> N >> K;

	if (K > N / 2)
	{
		cout << "0\n";
		return 0;
	}

	for (int n = 0; n <= N; n++)
	{
		dp[n][0] = 1;
		dp[n][1] = n;
	}

	for (int n = 2; n < N; n++)
	{
		for (int k = 2; k <= K; k++)
		{
			dp[n][k] = (dp[n - 1][k] + dp[n - 2][k - 1]) % MOD;
		}
	}


	int ans = (dp[N - 1][K] + dp[N - 3][K - 1]) % MOD;


	cout << ans << '\n';
	return 0;

}