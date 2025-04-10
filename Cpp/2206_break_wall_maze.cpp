#include <iostream>   
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

typedef tuple<int, int, int> tiii;

int N, M;
int maze[2][1000][1000];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int inputMaze[1000][1000];
int dist[2][1000][1000] = { 0 }; // separate distance/visited arrays for state 0 and state 1queue<tiii> q;

int bfs() {
    queue<tiii> q;
    // Start at (0,0) with state 0 (no wall broken)
    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 1;

    while (!q.empty())
    {
        int broken = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();

        // If reached the goal, return the distance
        if (x == N - 1 && y == M - 1)
            return dist[broken][x][y];

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check bounds
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            // Case 1: The next cell is a wall.
            if (inputMaze[nx][ny] == 1)
            {
                // We can only break the wall if we haven't done so already.
                if (broken == 0 && dist[1][nx][ny] == 0)
                {
                    dist[1][nx][ny] = dist[0][x][y] + 1;
                    q.push(make_tuple(1, nx, ny));
                }
            }
            // Case 2: The next cell is empty.
            else
            {
                // If we haven't visited this cell in the current state.
                if (dist[broken][nx][ny] == 0)
                {
                    dist[broken][nx][ny] = dist[broken][x][y] + 1;
                    q.push(make_tuple(broken, nx, ny));
                }
            }
        }
    }
    return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string line; cin >> line;
        for (int j = 0; j < M; ++j)
        {
            inputMaze[i][j] = line[j] - '0';
        }
	}

	cout << bfs();
	return 0;
}