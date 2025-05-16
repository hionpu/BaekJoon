#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

inline int popcount(unsigned int x) {
#if defined(__GNUC__) || defined(__clang__)
    return __builtin_popcount(x);
#elif defined(_MSC_VER)
    return __popcnt(x);
#else
    // Parallel bit count (Hacker's Delight)
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x3F;
#endif
}



using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N; cin >> N;

    vector<vector<int>> cost(N+1, vector<int>(N+1));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> cost[i][j];
        }
    }

    vector<int> dp(1 << N, INT_MAX);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << N); ++mask)
    {
        int workerCount = popcount(mask);
        if (workerCount < N)
        {
            for (int jobIdx = 0; jobIdx < N; ++jobIdx)
            {
                if ((mask & (1 << jobIdx)) == 0)
                {
                    dp[mask | (1 << jobIdx)] = min(dp[mask | (1 << jobIdx)], dp[mask] + cost[workerCount][jobIdx]);
                }
            }
        }
    }

    cout << dp[(1 << N) - 1] << '\n';
    return 0;
}