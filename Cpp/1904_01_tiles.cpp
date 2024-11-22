#include <iostream>   

using namespace std;
const int MAX_N = 1000000;
const int MOD = 15746;
int dp[MAX_N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i - 3] + 2*dp[i - 2]) % MOD;
    }

    cout << dp[n] << '\n';

    return 0;
}