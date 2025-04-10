#include <iostream>   


using namespace std;

int graph[50][50];
bool visited[50][50];

int dx[4] = { -1, 1, 0 , 0 };
int dy[4] = { 0,0,-1,1 };

int M, N;

int ans = 0;

void dfs(int x, int y) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx>=0 && xx<M && yy >=0 && yy <N && !visited[yy][xx] && graph[yy][xx] == 1)
        {
            dfs(xx, yy);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

    while (T--)
    {
        ans = 0;

        int K; cin >> M >> N >> K;

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                graph[y][x] = 0;
                visited[y][x] = false;
            }
        }

        for (int i = 0; i < K; ++i)
        {
            int x, y; cin >> x >> y;
            graph[y][x] = 1;
        }

        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                if (!visited[y][x] && graph[y][x] == 1)
                {
                    ans++;
                    dfs(x,y);
                }
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}