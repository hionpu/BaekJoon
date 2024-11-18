#include <iostream>   

using namespace std;
bool dp[1001] = { true, true, false, true, true };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[2] = false;
    int n;
    cin >> n;
    for (int i = 5; i <= n; i++)
    {
        dp[i] = !dp[i - 1] || !dp[i - 3] || !dp[i - 4];
    }
    string ans = dp[n] ? "SK" : "CY";
    cout << ans;
    return 0;
}