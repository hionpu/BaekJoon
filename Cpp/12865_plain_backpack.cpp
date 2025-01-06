#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    // Vector to store weights and values
    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> items[i].first >> items[i].second; // weight, value
    }

    // Initialize DP array
    vector<int> dp(K + 1, 0);

    // Iterate through each item
    for (int i = 0; i < N; ++i)
    {
        int weight = items[i].first;
        int value = items[i].second;

        // Iterate through capacities from K down to weight
        for (int j = K; j >= weight; --j)
        {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }
    }

    // The maximum value achievable with capacity K
    cout << dp[K] << '\n';

    return 0;
}
