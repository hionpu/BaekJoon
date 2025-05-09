#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, M;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

struct edge {
	int a;
	int b;
	int c;
};

auto cmp = [](edge& x, edge& y) -> bool
	{
		return x.c < y.c;
	};

void bfs(vector<vector<int>>& board, vector<vector<bool>>& visited, map<int, vector<pii>>& island, int y, int x, int idx) {
	queue<pii> q;
	q.push({ y,x });
	visited[y][x] = true;
	while (!q.empty())
	{
		pii fr = q.front();
		int cy = fr.first;
		int cx = fr.second;
		q.pop();

		island[idx].push_back({ cy,cx });

		for (int i = 0; i < 4; ++i)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx] && board[ny][nx] == 1)
			{
				visited[ny][nx] = true;
				q.push({ ny,nx });
			}
		}
	}
}

class DS {
private:
	vector<int> parent;
	vector<int> rank;
	vector<int> count;

public:
	DS(int n) {
		parent.resize(n+1);
		rank.resize(n+1);
		count.resize(n + 1,1);
		count[0] = 0;
		for (int i = 1; i <= n; ++i) parent[i] = i;
	}

	int get_parent(int a) {
		if (parent[a] == a) return a;
		return parent[a] = get_parent(parent[a]);
	}

	void unite(int a, int b) {
		int root_a = get_parent(a);
		int root_b = get_parent(b);

		if (root_a == root_b) return;

		if (rank[root_a] < rank[root_b])
		{
			parent[root_a] = root_b;
			count[root_b] += count[root_a];
			count[root_a] = 0;
		}
		else
		{
			parent[root_b] = root_a;
			count[root_a] += count[root_b];
			count[root_b] = 0;
			if (rank[root_a] == rank[root_b]) rank[root_a]++;
		}
	}

	bool connected(int a, int b) {
		return get_parent(a) == get_parent(b);
	}

	int get_count(int a) {
		return count[get_parent(a)];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// mark indices on islands
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M));
	vector<vector<int>> temp(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M, false));
	map<int, vector<pii>> island;

	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> board[y][x];
		}
	}
	int idx = 1;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (!visited[y][x] && board[y][x] != 0)
			{
				bfs(board, visited, island, y, x, idx++);
			}
		}
	}

	for (auto& kv : island)
	{
		for (auto& pos : kv.second)
		{
			temp[pos.first][pos.second] = kv.first;
		}
	}

	//for (int y = 0; y < N; ++y)
	//{
	//	for (int x = 0; x < M; ++x)
	//	{
	//		cout << temp[y][x] << ' ';
	//	}
	//	cout << '\n';
	//}

	//cout << '\n';

	// check connect is possible, min dist between islands
	int num_island = island.size();
	int inf = max(M, N) + 1;
	vector<vector<int>> graph(num_island + 1, vector<int>(num_island + 1, inf));

	for (auto& kv : island)
	{
		int this_island = kv.first;
		//visited.resize(N, vector<bool>(M, false));
		for (auto& pos : kv.second)
		{
			// for each direction
			for (int i = 0; i < 4; ++i)
			{
				// move by 1
				for (int j = 1; j < max(M, N); ++j)
				{
					int ny = pos.first + j * dy[i];
					int nx = pos.second + j * dx[i];

					if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1 || temp[ny][nx] == this_island) break;

					if (temp[ny][nx] != 0)
					{
						int dist = j - 1;
						if (dist < 2) break;
						int other_island = temp[ny][nx];
						graph[this_island][other_island] = graph[other_island][this_island] = min(graph[other_island][this_island], dist);
						break;
					}

				}
			}
		}
	}


	// Kruscal

	vector<edge> eg;
	for (int i = 1; i <= num_island; ++i)
	{
		for (int j = i + 1; j <= num_island; ++j)
		{
			if (graph[i][j] < inf && graph[i][j] >1)
			{
				eg.push_back({ i,j,graph[i][j] });
			}
		}
	}

	/*cout << '\n';

	for (int y = 1; y <= num_island; ++y)
	{
		for (int x = 1; x <= num_island; ++x)
		{
			cout << graph[y][x] << ' ';
		}
		cout << '\n';
	}*/


	sort(eg.begin(), eg.end(), cmp);
	DS ds(num_island);
	int ans = 0;
	for (auto& e : eg)
	{
		if (ds.connected(e.a, e.b)) continue;
		ds.unite(e.a, e.b);
		ans += e.c;
	}

	bool possible = false;
	for (int i = 1; i <= num_island;++i)
	{
		if (ds.get_count(i) == num_island)
		{
			possible = true;
			break;
		}
	}

	if (possible) cout << ans << '\n';
	else cout << -1 << '\n';

	return 0;
}