#include <iostream>   
#include <queue>
#include <algorithm>

using namespace std;
queue<int> q;
vector<int> connect[100001];
bool visited[100001];
int route[100001];

void bfs(int node) {
    int i = 1;
    visited[node] = true;
    q.push(node);
    while (!q.empty())
    {
        int fr = q.front();
        route[fr] = i++;
        q.pop();
        for (const auto& next : connect[fr])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
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
    
    bfs(R);

    for (int i = 1; i <= N; ++i) cout << route[i] << '\n';

    return 0;
}