#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void dynamic(vector<vector<int>>& graph, vector<int>& weight, vector<bool>& visited, vector<vector<int>>& dp, vector<bool>& track, int current) {
    if (visited[current])
    {
        return;
    }

    visited[current] = true;
    dp[current][0] = 0;
    dp[current][1] = weight[current];

    for (auto& child : graph[current])
    {
        if (visited[child]) continue;

        dynamic(graph, weight, visited, dp, track, child);
        
        if (dp[child][1] > dp[child][0])
        {
            dp[current][0] += dp[child][1];
            track[child] = true;
        }
        else
        {
            dp[current][0] += dp[child][0];
        }

        dp[current][1] += dp[child][0];
    }
}

void backtrack(vector<bool>& visited, vector<bool>& track,  vector<vector<int>>& graph, vector<int>& max_indep, int cur, bool chosen) {
    if (visited[cur]) return;
    visited[cur] = true;

    if (chosen)
    {
        max_indep.push_back(cur);
        for (auto& child : graph[cur])
        {
            if (visited[child]) continue;
            backtrack(visited, track, graph, max_indep, child, 0);
        }
    }
    else
    {
        for (auto& child : graph[cur])
        {
            if (visited[child]) continue;
            backtrack(visited, track, graph, max_indep, child, track[child]);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> weight(N+1);
    vector<vector<int>> graph(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> weight[i];
    }

    for (int i = 0; i < N - 1; ++i)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(N + 1);
    vector<vector<int>> dp(N + 1, vector<int>(2));
    vector<bool> track(N + 1);
  
    dynamic(graph, weight, visited, dp, track, 1);

    track[1] = dp[1][1] > dp[1][0] ? 1 : 0;

    visited.clear();
    visited.resize(N + 1);

    vector<int> max_indep;
    
    backtrack(visited, track, graph, max_indep, 1, track[1]);

    cout << max(dp[1][1], dp[1][0]) << '\n';
    sort(max_indep.begin(), max_indep.end());
    for (auto& n : max_indep)
    {
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}