#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class sns {

private:
    vector<vector<int>> graph;
    vector<vector<int>> dp;
    vector<bool> visited;
    vector<bool> isEA;

public:
    sns(int n) {
        graph.resize(n + 1);
        dp.resize(n + 1, vector<int>(2));
        visited.resize(n + 1);
        isEA.resize(n + 1);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void fill_dp(int cur) {
        if (visited[cur]) return;
        visited[cur] = true;
        // dp[i][0]: min number of total EA when i-th node is NOT EA.
        // dp[i][1]: min number of total EA when i-th node IS EA.

        dp[cur][1] = 1;

        for (auto& next : graph[cur])
        {
            if (visited[next]) continue;
            fill_dp(next);
            dp[cur][0] += dp[next][1];
            dp[cur][1] += min(dp[next][0], dp[next][1]);
        }
    }

    int get_min_EA(int i) {
        return min(dp[i][0], dp[i][1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;

    sns s(N);
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v; cin >> u >> v;
        s.add_edge(u, v);
    }

    s.fill_dp(1);

    cout << s.get_min_EA(1) << '\n';



    return 0;
}