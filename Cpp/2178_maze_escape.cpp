#include <iostream>   
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int graph[100][100];
bool visited[100][100];
int dist[100][100];
queue<pii> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int N, M;

void bfs(int i, int j) {
	visited[i][j] = 1;
	q.push(make_pair(i, j));

	while (!q.empty())
	{
		pii fr = q.front();
		
		
		q.pop();


		for (int k = 0; k < 4; ++k)
		{
			int ii = fr.first + dx[k];
			int jj = fr.second + dy[k];

			if (ii >= 0 && ii < N && jj >= 0 && jj < M && !visited[ii][jj] && graph[ii][jj] == 1)
			{
				visited[ii][jj] = 1;
				dist[ii][jj] = dist[fr.first][fr.second] + 1;
				q.push(make_pair(ii, jj));
			}
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string row; cin >> row;
		for (int j = 0; j < M; ++j)
		{
			graph[i][j] = row[j] - '0';
		}
	}

	bfs(0, 0);

	cout << dist[N-1][M-1]+1 << '\n';

	return 0;
}