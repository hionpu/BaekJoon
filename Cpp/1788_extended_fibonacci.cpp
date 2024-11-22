#include <iostream>   
#include <vector>

using namespace std;
const int MOD = 1000000000;
const int MAXN = 1000000;
//int dp[2000001];
int dp[MAXN + 1];

int& fibo(int idx) {
    return dp[idx + MAXN];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[1] = 1;

    if (n == 0)
    {
        cout << 0 << '\n' << 0;
        return 0;
    }
    int sign = (n < 0) && (n % 2 == 0) ? -1 : 1;
    
    for (int i = 2; i <= abs(n); i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << sign << '\n' << dp[abs(n)];

    return 0;
}


