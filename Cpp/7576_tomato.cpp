#include <iostream>   
#include <queue>

using namespace std;

typedef pair<int, int> pii;
int toms[1000][1000];
int days[1000][1000];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

queue<pii> q;
int M, N;
int unripe = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> toms[i][j];
            if (toms[i][j] == 1)
            {
                days[i][j] = 1;
                q.push(make_pair(i, j));
            }
        }
    }

    int lastDay = 0;
    while (!q.empty())
    {
        pii fr = q.front();
        int x = fr.first;
        int y = fr.second;
        lastDay = days[x][y];
       // if (unripe <= 0) break;
        q.pop();

        for (int n = 0; n < 4; ++n)
        {
            int nx = x + dx[n];
            int ny = y + dy[n];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && toms[nx][ny] == 0 && days[nx][ny] == 0)
            {
                toms[nx][ny] = 1;
                days[nx][ny] = days[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
   
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (toms[i][j] == 0)
                {
                    lastDay = 0;
                    break;
                }
            }
        }
    
    cout << lastDay-1 << '\n';
    return 0;
}