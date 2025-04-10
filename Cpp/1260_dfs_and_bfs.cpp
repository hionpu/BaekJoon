#include <iostream>   
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[10001];
queue<int> q;
bool dVisited[1001];
bool bVisited[1001];
int bOrder[1001];
int dOrder[1001];

int o = 1;
void dfs(int node) {
    dVisited[node] = 1;
    dOrder[o++] = node;

    for (const auto& next : graph[node])
    {
        if (!dVisited[next]) dfs(next);
    }
}

void bfs(int node) {
    bVisited[node] = 1;
    q.push(node);

    while (!q.empty())
    {
        int fr = q.front();
        bOrder[o++] = fr;
        q.pop();
        for (const auto& next : graph[fr])
        {
            if (!bVisited[next])
            {
                bVisited[next] = 1;
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int N, M, V; cin >> N >> M >> V;

    for (int i = 1; i <= M; ++i)
    {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    o = 1;
    bfs(V);

    for (int i = 1; i <= N; ++i)
    {
        if (dOrder[i] == 0) break;
        cout << dOrder[i] << " ";
    }

    cout << '\n';

    for (int i = 1; i <= N; ++i)
    {
        if (bOrder[i] == 0) break;

        cout << bOrder[i] << " ";
    }

    return 0;
}