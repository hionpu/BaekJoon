#include <iostream>   
#include <vector>
#include <algorithm>

using namespace std;

vector<int> connect[100001];
int visited[100001];
int counts[100001];
int currentCount = 1;

void dfs(int node) {
    visited[node] = 1;
    counts[node] = currentCount++;

    for (int i = 0; i < connect[node].size(); i++)
    {
        int nextNode = connect[node][i];
        if (visited[nextNode] == 0) dfs(nextNode);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, R; cin >> N >> M >> R;

    for (int i = 0; i < M; ++i)
    {
        int x, y; cin >> x >> y;
        connect[x].push_back(y);
        connect[y].push_back(x);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(connect[i].begin(), connect[i].end(), [](const int& a, const int& b) -> bool 
            {
                return a > b;
            });
    }

    dfs(R);

    for (int i = 1; i <= N; i++)
    {
        cout << counts[i] << '\n';
    }

    return 0;
}