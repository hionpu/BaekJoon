#include <iostream>   

using namespace std;
const int MAX_N = 2000;
int dp[MAX_N + 1][MAX_N + 1];
int arr[MAX_N + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    
    // odd
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < min(i,n-i+1); j++)
        {
            if (j == 0) dp[i][i] = 1; 
            else if (j == 1) dp[i-j][i + j] = arr[i - j] == arr[i + j] ? 1 : 0;
            else 
            {
                dp[i - j][i + j] = dp[i - j + 1][i + j - 1] == 1 ? (arr[i - j] == arr[i + j] ? 1 : 0):0;
            }

        }
    }

    // even
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= min(i - 1, n - i-1); j++)
        {
            if (j == 0) dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 0;
            else
            {
                dp[i - j][i + 1 + j] = dp[i - j + 1][i + j] == 1 ? (arr[i - j] == arr[i + 1 + j] ? 1 : 0) : 0;
            }
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }


    return 0;
}