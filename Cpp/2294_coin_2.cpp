#include <iostream>   

using namespace std;
int dp[10001] = { 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
	int coins[100] = { 0 };
	cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coins[i];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = coins[i]; j <= k; j++)
        {
			if (j == coins[i]) dp[j] = 1;
			else if (dp[j] == 0 && dp[j - coins[i]] != 0) dp[j] = dp[j - coins[i]] + 1;
			else if (dp[j] != 0 && dp[j - coins[i]] != 0) dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    dp[k] == 0 ? cout << -1 : cout << dp[k];

    return 0;
}