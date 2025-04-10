#include <iostream>   
#include <queue>
#include <vector>

using namespace std;

int V, E;
vector<int> graph[20001];
int colors[20001];
bool isBipart;

void bfs(int start, int color) {
	queue<int> q;
	q.push(start);
	colors[start] = color;

	while (!q.empty() && isBipart)
	{
		int fr = q.front();
		q.pop();

		for (auto const& next : graph[fr])
		{
			if (colors[next] == 0)
			{
				colors[next] = colors[fr] * -1;
				q.push(next);
			}
			else if (colors[fr] * colors[next] == 1)
			{
				isBipart = false;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int K; cin >> K;

	while (K--)
	{
		cin >> V >> E;
		isBipart = true;

		for (int i = 1; i <= V; ++i)
		{
			graph[i].clear();
			colors[i] = 0;
		}

		for (int i = 0; i < E; ++i)
		{
			int a, b; cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 1; i <= V; ++i)
		{
			if (!isBipart) break;
			if (colors[i] == 0)
			{
				bfs(i, 1);
			}
		}

		string ans = isBipart ? "YES" : "NO";
		cout << ans <<'\n';
	}


	return 0;
}