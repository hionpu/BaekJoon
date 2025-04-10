#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int manDist(pii i, pii j) {
    return abs(i.first - j.first) + abs(i.second - j.second);
}

pii reports[1000];

struct State {
    int cost;
    int prev_i, prev_j;
    int decision;
};

// https://www.acmicpc.net/source/77595996 1D array 참조코드
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, W; cin >> N >> W;

    
    for (int i = 1; i <= W; ++i)
    {
        cin >> reports[i].first >> reports[i].second;
    }

    vector<vector<State>> dp(W+1, vector<State>(W+1, { INT_MAX,-1,-1,0 }));

    dp[0][0] = { 0,-1,-1,0 };
    

    for (int i = 0; i <= W; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            int next = max(i, j)+1;
            if (next > W || dp[i][j].cost == INT_MAX) continue;

            pii loc_a = i == 0 ? pii(1, 1) : reports[i];
            pii loc_b = j == 0 ? pii( N,N ) : reports[j];

            int cost_a = dp[i][j].cost + manDist(reports[next], loc_a);
            int cost_b = dp[i][j].cost + manDist(reports[next], loc_b);

            if (cost_a < dp[next][j].cost)
            {
                dp[next][j] = { cost_a,i,j,1 };
            }

            if (cost_b < dp[i][next].cost)
            {
                dp[i][next] = { cost_b,i,j,2 };
            }
        }
    }

    int ans = INT_MAX;
    int final_i = -1, final_j = -1;

    for (int i = 1; i <= W; ++i)
    {
        if (dp[W][i].cost < ans)
        {
            ans = dp[W][i].cost;
            final_i = W;
            final_j = i;
        }

        if (dp[i][W].cost < ans)
        {
            ans = dp[i][W].cost;
            final_i = i;
            final_j = W;
        }
    }
    cout << ans << '\n';

    vector<int> path;
    int i = final_i, j = final_j;
    while (i + j > 0)
    {
        path.push_back(dp[i][j].decision);
        int ii = dp[i][j].prev_i;
        int jj = dp[i][j].prev_j;
        i = ii; j = jj;
    }

    reverse(path.begin(), path.end());

    for (auto& x : path)
    {
        cout << x << '\n';
    }
    return 0;
}