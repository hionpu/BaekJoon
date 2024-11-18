#include <iostream>   
#include <vector>

using namespace std;
int dp[1001];
int arr[1001];
int trace[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int maxLength = 0;
    int lastIndex = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
        trace[i] = 0;
        for (int j = 1; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = max(dp[i], dp[j] + 1);
                trace[i] = j;
            }
        }

        if (dp[i] > maxLength)
        {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    vector<int> lis;
    while (lastIndex != 0)
    {
        lis.push_back(arr[lastIndex]);
        lastIndex = trace[lastIndex];
    }

    reverse(lis.begin(), lis.end());

    cout << maxLength << '\n';

    for (int num : lis)
    {
        cout << num << ' ';
    }
    cout << '\n';

    return 0;
}