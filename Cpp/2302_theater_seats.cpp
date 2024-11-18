#include <iostream>   
#include <vector>

int dp[41];
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp[0] = 1;
    dp[1] = 1;
    int n, m, lastVipNum;
    int ans = 1;
    cin >> n >> m;
    vector<int> segLengths;
    lastVipNum = 0;

    for (int i = 2; i <= 40; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    for (int i = 0; i < m; i++)
    {
        int vipNum;
        cin >> vipNum;
        ans *= dp[vipNum - lastVipNum - 1];
        lastVipNum = vipNum;
    }
    
    ans *= dp[n - lastVipNum];

    cout << ans << '\n';

    return 0;
}