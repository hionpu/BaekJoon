#include <iostream> 
#include <climits>

using namespace std;
const int C_MAX = 500;
int dp[C_MAX][C_MAX];
int sums[C_MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

   

    while (T--)
    {
        int K; cin >> K;
     
        for (int i = 0; i < K; i++)
        {
            int c; cin >> c;
            dp[i][i] = 0;
            if (i == 0) sums[i] = c;
            else sums[i] = sums[i - 1] + c;
        }

        for (int len = 2; len <= K; len++)
        {
            for (int i = 0; i <= K - len + 1; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int partialSum = i == 0 ? sums[j] : sums[j] - sums[i - 1];
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + partialSum);
                }
            }
        }

        cout << dp[0][K - 1] << '\n';
    }

    return 0;
}