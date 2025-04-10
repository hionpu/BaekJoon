#include <iostream>   
#include <queue>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];
queue<int> q;
int numVirus = 0;

void dfs(int node) {
	numVirus++;
	visited[node] = 1;

	for (const auto& next : graph[node])
	{
		if (!visited[next])
		{
			visited[next] = 1;
			dfs(next);
		}
	}
}

void bfs(int node) {
	visited[node] = 1;
	q.push(node);

	while (!q.empty())
	{
		int fr = q.front();
		numVirus++;
		q.pop();
		for (const auto& next : graph[fr])
		{
			if (!visited[next])
			{
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;

	for (int i = 1; i <= M; ++i)
	{
		int x, y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	//dfs(1);
	bfs(1);

	cout << numVirus -1<< '\n';

	return 0;
}