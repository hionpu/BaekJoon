#include <iostream>   
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int moves[300][300];
int N, destX, destY;
queue<pii> q;

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	moves[x][y] = 1;

	while (!q.empty())
	{
		pii fr = q.front();
		int x = fr.first;
		int y = fr.second;
		if (x == destX && y == destY) break;
		q.pop();

		for (int d = 0; d < 8; ++d)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && moves[nx][ny] == 0)
			{
				moves[nx][ny] = moves[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
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
		int oriX, oriY;
		cin >> N >> oriX >> oriY >> destX >> destY;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				moves[i][j] = 0;
			}
		}
		
		while (!q.empty()) q.pop();

		bfs(oriX, oriY);
		cout << moves[destX][destY]-1 << '\n';
	}


	return 0;
}