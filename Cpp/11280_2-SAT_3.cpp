#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <functional>
#include <stack>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	map<int, vector<int>> graph;
	map<int, int> id;
	map<int, bool> finished;
	vector<vector<int>> Scc;
	map<int, int> nodeToScc;
	int sccNum = 0;
	int idx = 0;

	for (int i = 0; i < M; ++i)
	{
		int a, b; cin >> a >> b;
		graph[-a].push_back(b);
		graph[-b].push_back(a);
	}

	for (int i = -N; i <= N && i != 0; ++i)
	{
		id[i] = 0;
		finished[i] = false;
	}

	stack<int> q;

	function<int(int)> DFS = [&](int n) -> int
		{
			id[n] = ++idx;
			q.push(n);

			int result = id[n];
			for (auto& next : graph[n])
			{
				if (id[next] == 0) result = min(result, DFS(next));
				else if (!finished[next]) result = min(result, id[next]);
			}

			if (result == id[n])
			{
				vector<int> scc;

				while (true)
				{
					int top = q.top();
					q.pop();
					finished[top] = true;
					scc.push_back(top);
					nodeToScc[top] = sccNum;
					if (top == n) break;
				}

				Scc.push_back(scc);
				sccNum++;
			}

			return result;
		};

	for (int i = -N; i <= N; ++i)
	{
		if (i == 0) continue;
		if (id[i] == 0) DFS(i);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (nodeToScc[i] == nodeToScc[-i])
		{
			cout << 0 << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';

	return 0;
}