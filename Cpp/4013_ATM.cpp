#include <iostream>   
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>
#include <functional>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> cash;
vector<bool> isRest;
vector<vector<int>> SCC;
vector<int> id;
vector<bool> finished;
stack<int> s;
int idNum;
int sccNum;
vector<int> nodeToScc;
vector<int> sccInDegree;
vector<bool> sccContainRest;
vector<vector<int>> sccGraph;
vector<int> sccTotalCash;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M; cin >> N >> M;
	graph.resize(N + 1);
	cash.resize(N + 1);
	id.resize(N + 1);
	finished.resize(N + 1);
	nodeToScc.resize(N + 1);
	idNum = 1;
	sccNum = 0;
	isRest.assign(N + 1, 0);
	for (int i = 0; i < M; ++i)
	{
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= N; ++i)
	{
		cin >> cash[i];
	}

	// S: start node, P: # of restaurant
	int S, P;
	cin >> S >> P;
	for (int i = 0; i < P; ++i)
	{
		int restaurant; cin >> restaurant;
		isRest[restaurant] = true;
	}

	function<int(int)> DFS = [&](int n) -> int
		{
			id[n] = idNum++;
			s.push(n);

			int result = id[n];

			for (auto& next : graph[n])
			{
				if (id[next] == 0)
				{
					result = min(result, DFS(next));
				}
				else if (!finished[next])
				{
					result = min(result, id[next]);
				}


			}
			if (result == id[n])
			{
				vector<int> scc;
				int totalCash = 0;
				while (true)
				{
					int top = s.top();
					s.pop();
					finished[top] = true;
					scc.push_back(top);
					nodeToScc[top] = sccNum;
					totalCash += cash[top];
					if (top == n) break;
				}

				SCC.push_back(scc);
				sccTotalCash.push_back(totalCash);
				sccNum++;
			}
			return result;
		};

	for (int node = 1; node <= N; ++node)
	{
		if (id[node] == 0) DFS(node);
	}

	sccGraph.resize(sccNum);
	sccInDegree.assign(sccNum, 0);
	sccContainRest.assign(sccNum, false);
	for (int node = 1; node <= N; ++node)
	{
		int sccA = nodeToScc[node];
		for (auto& next : graph[node])
		{
			int sccB = nodeToScc[next];
			if (sccA != sccB)
			{
				sccGraph[sccA].push_back(sccB);
				sccInDegree[sccB]++;
			}
		}

		if (isRest[node] && !sccContainRest[sccA])
		{
			sccContainRest[sccA] = true;
		}
	}

	vector<int> maxCash(sccNum, 0);
	queue<int> q;
	int startScc = nodeToScc[S];
	maxCash[startScc] = sccTotalCash[startScc];

	for (int i = 0; i < sccNum; ++i)
	{
		if (sccInDegree[i] == 0) q.push(i);
	}


	bool flag = false;
	while (!q.empty())
	{
		int current = q.front();
		q.pop();


		if (current == startScc) flag = true;
		for (int next : sccGraph[current])
		{
			if (flag)
			{
				maxCash[next] = max(maxCash[next], maxCash[current] + sccTotalCash[next]);
			}
			if (--sccInDegree[next] == 0)
			{
				q.push(next);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < sccNum; ++i)
	{
		if (sccContainRest[i]) ans = max(ans, maxCash[i]);
	}

	cout << ans << '\n';

	return 0;
}